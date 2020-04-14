# Server Demo

This server demo illustrates some important generalizable concepts:

### Serializability

Serialization is the process by which an object in memory, which is just a bunch of binary data, is converted to and frozen into a form that can be stored or transmitted. In a web context, this is generally done by converting an object's properties into JSON (JavaScript Object Notation) form; that's how Twitter and Discord do it. (JSON stores data using key-value pairs; which means, it consists of a list of labeled pieces of data. It's very similar to a plain object in JavaScript or a dict in Python. [More info here.](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON)) So, I added a to_json() method to the PaymentReciept class, which uses the [nlohmann/json](https://github.com/nlohmann/json) library's C++ json data type:
```
nlohmann::json PaymentReceipt::to_json()
{
	return {
		{"time", timestamp},  // key: "time", value: whatever the timestamp property is set to
		{"amount", amount},
		{"paymentMethod", paymentMethod}
	};
}
```
So we can create a PaymentReciept object, and then create a serializable JSON version:
```
PaymentReceipt pr = PaymentReceipt(timestamp, 35.01, "american express");
nlohmann::json prjson = pr.to_json();
```
And set up a path for it to be retrieved by the client browser:
```
svr.Get("/reciept", [prjson](const httplib::Request &req, httplib::Response res){
  res.set_content(prjson.dump(), "application/json");
}
```
And retrieve it in JavaScript in the client-side code and add it to the page:
```
function loadReciept(){
    fetch('/reciept').then(r=>r.json().then(reciept => {
        const location = document.querySelector('#recieptLocation');
        location.innerHTML += "amount: $" + reciept.amount + "<br>";
        location.innerHTML += "payment method: " + reciept.paymentMethod + "<br>";
        location.innerHTML += "payment time: " + (new Date(reciept.time*1000)).toLocaleString();
    }));
}
```
I think that pattern will generally show up a few times.

### Serving from 0.0.0.0 and port 1111
```
svr.listen("0.0.0.0", 1111);
```
The 0.0.0.0 means that the server will serve from wherever possible, including a) http://localhost:1111 if the browser is on the same machine as the server, b) your computer's local IP address (probably 192.168 dot something dot something:1111) to other machines on your local network (so, other machines connected to your router) and c) on the public internet (plus ":1111") at your public IP address (which you can discover by googling "my public IP"), if your device is directly connected to a modem or if you set up port forwarding on your router so that requests for port 1111 will go to your device.

### Serving static files
The server will make our static files, in the html folder under the root directory of the repository, available at the root path of the server:
```
auto ret = svr.set_mount_point("/", "../html");
```
So a request to (for example) http://localhost:1111/dogs.jpg will automatically serve the file from html/dogs.jpg on your machine, and also requests for just http://localhost:1111/ will serve the html/index.html file, because that's what files named "index.html" are for.

Serving static, empty-ish html files that retrieve serialized data from the server with JavaScript functions and then add it to the page is an extremely common pattern in web design; it's now generally considered preferable to generating HTML on the server that displays data and serving that (mostly because the page will have to change according to user input, which will involve modifying the page with JavaScript, so you might as well go all-in on using JavaScript to populate the content of the page.)

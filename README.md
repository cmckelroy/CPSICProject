# CPSIC Project (Software Engineering 33901)
The Coronavirus Pandemic System Integrated Control (CPSIC)

poop - socrates

## Compilation
.sln files are provided to make it easy to open and compile projects with Microsoft Visual Studio 2019. You don't have to edit the code with Visual Studio, but it is Highly Recommended to compile everything with the Visual Studio compiler (which can be used from the command line, with the VSCode editor, or probably with other IDEs) so we can compile each other's code without getting any weird surprises.
#### Currently available Visual Studio solutions:
 - CPSICClasses.sln - for compiling all the essential CPSIC classes into a static library; most useful just for checking them for compile errors.
  - ServerDemo/ServerDemo.sln - for building a .exe that runs a very simple demo web server.

## Style Guide (just for consistency)
 - Normal variable names will be in camel case: thisIsAVariable
 - Class names will be in pascal case: ThisIsAClass
 - Method names will have their words separated by underscores: this_is_a_method()

## Timestamps
Timestamps should be stored with the built-in C++ `time_t` type, like this:
```
#include <chrono>
time_t currentTime = time(nullptr);  // gets timestamp representing current time
```
Using ints as timestamps is not recommended because technically they'll run out of space sometime in 2038.

## External libraries
Documentation for the HTTP server library: https://github.com/yhirose/cpp-httplib

Documentation for the JSON library: https://github.com/nlohmann/json

Documentation for the MySQL connection library: https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-introduction.html

Github repository for MySQL Connector C++: https://github.com/mysql/mysql-connector-cpp

## Design documentation:
[Latest turned-in version of the SRS](https://drive.google.com/open?id=1tIDo6EWX_xK_nB-DwEnfQgoEU8oRWzPt3jOAZyB4Jg0)

[Latest use-case specification](https://drive.google.com/open?id=1RoIEqYQm-elgwrnmrjtSdCi6PAy0tDGX9izxc_K_KzQ)

[Original version of the SRS](https://docs.google.com/document/d/13YBdxYo1FdsuRPaPiD1YbAq0I3CzMSwm22LdRc1uAog/edit?usp=sharing)

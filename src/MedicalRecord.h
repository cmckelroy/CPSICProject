
#include <vector>
#include <string>
using std::vector;
//this class contains the health records of a patient and some stats on their health
class MedicalRecord {
private:
	vector<std::string> healthRecords;
	bool hasShownFluSymptoms;
	bool isInfected;
	bool hasSoughtCounseling;
public:
	MedicalRecord();	//default - healthRecords remain empty, all stats are set to false
	MedicalRecord(vector<std::string>healthRecords, bool symp, bool inf, bool couns);

	//accessor functions
	//accesor for healthRecords
	vector<std::string> get_docs();
	//accessor for flu symptom stat
	bool symptoms();
	//accessor for isInfected stat
	bool infection_status();
	//accessor for hasSoughtCounseling stat
	bool sought_counseling();

	//set functions
	void set(vector<std::string> healthRecords, bool symp, bool inf, bool couns);

};
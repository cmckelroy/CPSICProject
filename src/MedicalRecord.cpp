#include "MedicalRecord.h"
MedicalRecord::MedicalRecord() : healthRecords(), hasShownFluSymptoms(false), isInfected(false), hasSoughtCounseling(false) {

}
MedicalRecord::MedicalRecord(vector<std::string>healthRecords, bool symp, bool inf, bool couns) : healthRecords(healthRecords), hasShownFluSymptoms(symp), isInfected(inf), hasSoughtCounseling(couns) {

}

vector<std::string> MedicalRecord::get_docs() {
	return healthRecords;
}

bool MedicalRecord::symptoms() {
	return hasShownFluSymptoms;
}

bool MedicalRecord::infection_status() {
	return isInfected;
}

bool MedicalRecord::sought_counseling() {
	return hasSoughtCounseling;
}

void MedicalRecord::set(vector<std::string> docs, bool symp, bool inf, bool couns) {
	healthRecords = docs;
	hasShownFluSymptoms = symp;
	isInfected = inf;
	hasSoughtCounseling = couns;
}
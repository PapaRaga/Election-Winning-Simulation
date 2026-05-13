#include <vector>
#include "header.h"

//Constructors and default constructors for all classes
Issue::Issue(std::string _issue,std::string _description){
    issue = _issue;
    description = _description;
}

Stance::Stance(double _significance,double _measure){
    significance = _significance;
    measure = _measure;
}

Division::Division(std::string _name,double _population,std::vector<Stance>& _stances){
    name = _name;
    population = _population;
    stances = _stances;
}

PartyMember::PartyMember(double _popularity,std::string _partyName){
    //name = _name;
    popularity = _popularity;
    partyName = _partyName;
}
PartyMember::PartyMember(){}

Candidate::Candidate(std::string _name,double popularity,std::string partyName,std::vector<Stance>& _stances):PartyMember(popularity,partyName){
    name = _name;
    stances = _stances;
}

Leader::Leader(std::string _name,double popularity,std::string partyName):PartyMember(popularity,partyName){
    name = _name;
}
Leader::Leader():PartyMember(){}

Party::Party(std::string _name,Leader _leader,std::vector<Candidate>& _candidates){
    name = _name;
    leader = _leader;
    candidates = _candidates;
}

ElectionDay::ElectionDay(){}

Campaign::Campaign(std::vector<Party>& _parties,std::vector<Division>& _divisions, int _numofDays,int _numofDivisions,std::vector<Issue>& _issues,ElectionDay _electionDay){
    parties = _parties;
    divisions = _divisions;
    numofDays = _numofDays;
    numofDivisions = _numofDivisions;
    issues = _issues;
    electionDay = _electionDay;
}

EventDay::EventDay(double _occurrence,std::string _description,std::string _eventType){
    occurrence = _occurrence;
    description = _description;
    eventType = _eventType;
}

ElectionDay::ElectionDay(std::vector<double>& _coefficients){
    coefficients = _coefficients;
}

Party::Party(){}

//Getter functions for all attributes needed in the program
std::vector<Party>& Campaign::getParties(){
    return parties;
}

std::string Party::getPartyName(){
    return name;
}
Leader& Party::getLeader(){
    return leader;
}

std::string Leader::getLeaderName(){
    return name;
}

std::string Candidate::getCandidateName(){
    return name;
}
double PartyMember::getPopularity(){
    return popularity;
}
std::vector<Candidate>& Party::getCandidates(){
    return candidates;
}
std::vector<Stance>& Candidate::getStances(){
    return stances;
}

double Stance::getMeasure(){
    return measure;
}

double Stance::getSignificance(){
    return significance;
}

std::string Division::getDivisionName(){
    return name;
}
double Division::getPopulation(){
    return population;
}
std::vector<Stance>& Division::getDivisionStances(){
    return stances;
}

int Campaign::getNumOfDivisions(){
    return numofDivisions;
}

std::vector<Division>& Campaign::getDivisions(){
    return divisions;
}

std::vector<Issue>& Campaign::getIssues(){
    return issues;
}

double EventDay::getOccurrence(){
    return occurrence;
}

std::string EventDay::getDescription(){
    return description;
}

int Campaign::getNumOfDays(){
    return numofDays;
}

std::string EventDay::getEventType(){
    return eventType;
}

std::string PartyMember::getPartyName(){
    return partyName;
}

std::string Issue::getIssueDescription(){
    return description;
}

ElectionDay& Campaign::getElectionDay(){
    return electionDay;
}

std::vector<double>& ElectionDay::getCoefficients(){
    return coefficients;
}
//Setter functions to set a party member (Leader or Candidate)'s popularity and the stance's measure and significance
void PartyMember::setPopularity(double newPopularity){
    popularity = newPopularity;
}

void Stance::setMeasure(double newMeasure){
    measure = newMeasure;
}

void Stance::setSignificance(double newSignificance){
    significance = newSignificance;
}

//The function below is used to obtain the candidates of a division index and put them in a vector
std::vector<Candidate> Campaign::getCandidatesInDivision(int index){
    std::vector<Candidate> divisionCandidates;
    for(std::vector<Candidate>::size_type i = 0; i < this->getParties().size(); i++){
        divisionCandidates.push_back(this->getParties()[i].getCandidates()[index]);
    }
    return divisionCandidates;
}


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <vector>

//Declaring the classes needed for the program derived from the specification
class Issue{
    private:
        std::string issue;
        std::string description;
    public:
        Issue(std::string issue,std::string description);
        std::string getIssueDescription();
};

class Stance{
    private:
        double significance;
        double measure;
    public:
        Stance(double significance,double measure);
        double getSignificance();
        double getMeasure();
        void setSignificance(double newSignificance);
        void setMeasure(double newMeasure);
};

class Division{
    private:
        std::string name;
        double population;
        std::vector<Stance> stances;
    public:
        Division(std::string name,double population,std::vector<Stance>& stances);
        std::string getDivisionName();
        double getPopulation();
        std::vector<Stance>& getDivisionStances();
};
//Creating a PartyMember class to function as a base class for Leader and Candidate (using inheritance)
class PartyMember{
    private:
        double popularity;
        std::string partyName;
    public:
        PartyMember(double popularity,std::string partyName);
        PartyMember();
        double getPopularity();
        void setPopularity(double newPopularity);
        std::string getPartyName();
};

class Candidate: public PartyMember{
    private:
        std::string name;
        std::vector<Stance> stances;
    public:
        Candidate(std::string name,double popularity,std::string partyName,std::vector<Stance>& stances);
        std::vector<Stance>& getStances();
        std::string getCandidateName();
};

class Leader: public PartyMember{
    private:
        std::string name;
    public:
        Leader(std::string name,double popularity,std::string partyName);
        Leader();
        std::string getLeaderName();
};

class Party{
    private:
        std::string name;
        Leader leader;
        std::vector<Candidate> candidates;
    public:
        Party(std::string name,Leader _leader,std::vector<Candidate>& candidates);
        std::string getPartyName();
        Leader& getLeader();
        std::vector<Candidate>& getCandidates();
        Party();
};

class ElectionDay{
    private:
        std::vector<double> coefficients;
    public:
        ElectionDay(std::vector<double>& coefficients);
        std::vector<double>& getCoefficients();
        ElectionDay();
};

//The Campaign object will hold all instances needed to simulate Verdeloria's electoions
class Campaign{
    private:
        std::vector<Party> parties;
        std::vector<Division> divisions;
        std::vector<Issue> issues;
        int numofDays;
        int numofDivisions;
        ElectionDay electionDay;
    public:
        Campaign(std::vector<Party>& parties,std::vector<Division>& divisions, int numofDays,int numofDivisions,std::vector<Issue>& issues,ElectionDay electionDay);
        std::vector<Party>&getParties();
        int getNumOfDivisions();
        std::vector<Division>&getDivisions();
        std::vector<Issue>& getIssues();
        int getNumOfDays();
        std::vector<Candidate> getCandidatesInDivision(int index);
        ElectionDay& getElectionDay();
        void partyReport();
        void nationReport();
        void campaignEvents();
        void results();
        void displayIssues();
};

class EventDay{
    private:
        double occurrence;
        std::string description;
        std::string eventType;
    public:
        EventDay(double occurrence,std::string description,std::string eventType);
        double getOccurrence();
        std::string getDescription();
        std::string getEventType();
};

Campaign nationInitialization(int numOfDivisions, int numOfElectoralDays);
#endif // HEADER_H_INCLUDED

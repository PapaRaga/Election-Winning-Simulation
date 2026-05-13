#include <iostream>
#include <vector>
#include <random>
#include "header.h"
#include <iomanip>
#include <ctime>
#include <cmath>

//This function generates a party report, displaying the party names,leaders,candidates and their stances.
void Campaign::partyReport(){
    //Printing a formatted header to distinguish the party report from other functions of the program
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(52)<<" "<<"Party Report"<<std::endl;
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    //Looping through each party and start to display their information by printing the leader and party name.
    for(std::vector<Party>::size_type i = 0; i < this->getParties().size();i++){
        std::cout<<"\n";
        std::cout<<"Party Name: "<< this->getParties()[i].getPartyName()<<std::endl;
        std::cout<<"--------------------Party Leader---------------------"<< std::endl;
        std::cout<<"Leader Name: " << this->getParties()[i].getLeader().getLeaderName()<<std::endl;
        std::cout<<"Leader Popularity: "<< this->getParties()[i].getLeader().getPopularity()<<std::endl;
        std::cout<<"---------------------Candidates----------------------"<<std::endl;
        //Looping through each candidate of the party with index i and printing their name and popularity
        for(std::vector<Candidate>::size_type j = 0; j < this->getParties()[i].getCandidates().size();j++){
            std::cout<<"Candidate Name: "<< this->getParties()[i].getCandidates()[j].getCandidateName()<<std::endl;
            std::cout<<"Candidate Popularity: "<< this->getParties()[i].getCandidates()[j].getPopularity()<<std::endl;
            std::cout<<"-----------------Stances----------------"<<std::endl;
            //Looping through the current candidate's stances and printing them
            for(std::vector<Stance>::size_type k = 0; k < this->getParties()[i].getCandidates()[j].getStances().size();k++){
                std::cout<<"Stance for issue "<<k+1<<": ("<<this->getParties()[i].getCandidates()[j].getStances()[k].getSignificance()<<", "
                <<this->getParties()[i].getCandidates()[j].getStances()[k].getMeasure()<<")"<<std::endl;
            }
            std::cout<<"\n";
            //Printing this line to seperate the candidates of the party unless it is the last one.
            if(j != this->getParties()[i].getCandidates().size() -1){
                std::cout<<"-----------------------------------------------------"<<std::endl;
            }
        }
        //Printing this seperator for parties, unless it is the last one.
        if(i != this->getParties().size() - 1){
            std::cout<<"\n";
            std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
        }
    }
}

//This function generates a nation report, displaying information about each division and their stances
void Campaign::nationReport(){
    //Printing a formatted header to distinguish the party report from other functions of the program
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(53)<<" "<<"Nation Report"<<std::endl;
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    //Looping through all the divisions in the campaign
    for(int i = 0 ; i < this->getNumOfDivisions();i++){
        std::cout<<"-----------------------Division "<<i+1<<"-----------------------"<<std::endl;
        std::cout<<"Name: "<<this->getDivisions()[i].getDivisionName()<<std::endl;
        std::cout<<"Population: "<<this->getDivisions()[i].getPopulation()<<std::endl;
        std::cout<<"-----------------Stances-----------------"<<std::endl;
        //Looping through and printing all the stances of the current division
        for(std::vector<Stance>::size_type j = 0; j < this->getDivisions()[i].getDivisionStances().size();j++){
            std::cout<<"Stance for issue "<<j+1<<": ("<<this->getDivisions()[i].getDivisionStances()[j].getSignificance()<<", "
            <<this->getDivisions()[i].getDivisionStances()[j].getMeasure()<<")"<<std::endl;
        }
        std::cout<<std::endl;
    }
}
//This function initializes a campaign object with divisions, parties, leaders, candidates, and issues
Campaign nationInitialization(int numOfDivisions, int numOfElectoralDays){
    //Predefined containers holding the names of parties, leaders, candidates and divisions
    std::vector<std::string> partyNames = {"Straw Hat Party","Red Haired Party","Cross Guild Party"};
    std::vector<std::string> leaderNames = {"Luffy","Shanks","Buggy"};
    std::vector<std::string> divisionNames = {"Dressrosa","Alabasta","Skypiea","Punk Hazard"," Whole Cake Island","Sabaody Archipelago","Fish-Man Island"," Wano Country","Laugh Tale"," Thriller Bark"};
    std::vector<std::string> strawCandidates = {"Zoro","Nami","Usopp","Sanji","Chopper","Robin","Franky","Brook","Jinbei","Yamato"};
    std::vector<std::string> redCandidates = {"Benn Beckman","Yasopp","Lucky Roux","LimeJuice","Hongo","Bonk Punch","Monster","Building Snake","Howling Gab","Marco"};
    std::vector<std::string> crossCandidates = {"Crocodile","Mihawk","Galdino","Alvida","Cabaji","Mohji","Richie","Daz Bones","Perona","Bon Clay"};

    //Initializing the list of issues
    std::vector<Issue> issues;
    Issue issue1 = Issue("Global warming","Global warming, caused by human activity, threatens Verdeloria's ecosystems, agriculture, and tourism. Urgent action is needed to cut emissions and promote renewable energy for a sustainable future.");
    Issue issue2 = Issue("Rights of pets","Pet rights in Verdeloria focus on humane treatment and protection, reflecting the nation's values. Ensuring these rights prevents animal abuse and promotes responsible ownership.");
    Issue issue3 = Issue("Quality Education","Quality education in Verdeloria ensures equal access, effective teaching, and ample resources, crucial for the nation's future. It fosters a skilled workforce and drives economic growth.");
    Issue issue4 = Issue("Public Health","Public health in Verdeloria focuses on protecting citizens through policies and healthcare access, crucial for improving life expectancy and quality of life, and supporting social and economic prosperity.");
    Issue issue5 = Issue("Infrastructure","Maintaining and improving infrastructure is vital for economic growth, public services, and quality of life, and it helps attract foreign investment and global competitiveness.");

    issues.push_back(std::move(issue1));
    issues.push_back(std::move(issue2));
    issues.push_back(std::move(issue3));
    issues.push_back(std::move(issue4));
    issues.push_back(std::move(issue5));

    //Creating the random distribution for stances and population
    std::normal_distribution<> stance(0.5,0.15); //normal distribution
    std::uniform_real_distribution<> population(0.5,1.5000001); //uniform distributions
    std::default_random_engine rndEng(time(0));
    //Initializing divisions with randomly generated stances
    std::vector<Division> divisions;
    double significance;
    double measure;
    for(int i = 0; i < numOfDivisions;i++){
        std::vector<Stance> divisionStances;
        for(std::vector<Issue>::size_type j = 0; j < issues.size(); j++){
            significance =  stance(rndEng);
            measure = stance(rndEng);
            Stance stance = Stance(significance,measure);
            divisionStances.push_back(std::move(stance));
        }
        Division division(divisionNames[i],population(rndEng),divisionStances);
        divisions.push_back(std::move(division));
    }
    //Initializing party leaders with random popularity
    std::vector<Leader> leaders;
    std::uniform_real_distribution<> popularity(0.0001,1.0001);
    for(std::vector<std::string>::size_type i = 0; i < partyNames.size();i++){
        Leader leader = Leader(leaderNames[i],popularity(rndEng),partyNames[i]);
        leaders.push_back(std::move(leader));
    }
    std::vector<Stance> strawStances;
    std::vector<Stance> crossStances;
    std::vector<Stance> redStances;
    //Initializing party candidates and assign stances
    for(std::vector<std::string>::size_type i = 0; i < partyNames.size();i++){
        for(std::vector<Issue>::size_type j = 0; j < issues.size();j++){
            significance =  stance(rndEng);
            measure = stance(rndEng);
            //Creating a stance object so every candidate of the same party has the same initial stances
            Stance stance = Stance(significance,measure);
            if(i == 0){
                strawStances.push_back(std::move(stance));
            }
            else if(i == 2){
                crossStances.push_back(std::move(stance));
            }
            else if(i == 1){
                redStances.push_back(std::move(stance));
            }
        }
    }
    //Creating party objects and adding them to a vector parties
    std::vector<Party> parties;
    //The first loop uses the number of parties and the nested loop uses the number divisions ensuring that the correct number of candidates is added to each party
    for(std::vector<std::string>::size_type i = 0; i < partyNames.size();i++){
        std::vector<Candidate> candidates;
        for(int j = 0; j < numOfDivisions; j++){
            if(i == 0){
                Candidate candidate = Candidate(strawCandidates[j],popularity(rndEng),partyNames[i],strawStances);
                candidates.push_back(std::move(candidate));
            }
            else if(i == 1){
                Candidate candidate = Candidate(redCandidates[j],popularity(rndEng),partyNames[i],redStances);
                candidates.push_back(std::move(candidate));
            }
            else if(i == 2){
                Candidate candidate = Candidate(crossCandidates[j],popularity(rndEng),partyNames[i],crossStances);
                candidates.push_back(std::move(candidate));
            }
        }
        Party party = Party(partyNames[i],leaders[i],candidates);
        parties.push_back(std::move(party));
    }
    //Creating ElectionDay object with coefficients
    std::vector<double> coefficients = {0.5,0.3,0.2};
    ElectionDay electionDay = ElectionDay(coefficients);
    //Creating the campaign object
    Campaign campaign = Campaign(parties,divisions,numOfElectoralDays,numOfDivisions,issues,electionDay);
    return campaign;
}

void Campaign::campaignEvents(){
    //Creating EventDay objects for different types of events
    EventDay divisionEvent = EventDay(0.15,"The people are becoming dissatisfied with the election and are less interested on the nation's issues.","Division");
    EventDay leaderEvent = EventDay(0.2,"The leader delivered a highly acclaimed speech outlining a comprehensive plan for national reform.","Leader");
    EventDay candidateEvent1 = EventDay(0.15,"The candidate was caught using generative AI to write their agenda.","Candidate");
    EventDay candidateEvent2 = EventDay(0.3,"The candidate has adopted a comprehensive new platform, shifting their approach to all key issues following \nan in-depth consultation with policy experts.","Candidate");

    std::vector<EventDay> events;
    events.push_back(std::move(divisionEvent));
    events.push_back(std::move(leaderEvent));
    events.push_back(std::move(candidateEvent1));
    events.push_back(std::move(candidateEvent2));

    //Creating a random number generator for event probabilities and changes in popularity/stances
    std::default_random_engine rndEng(time(0));
    std::uniform_real_distribution<> eventProbability(0,1);
    std::normal_distribution<> changePopularity(0.1,0.05);
    std::normal_distribution<> changeStances(0.1,0.05);
    std::vector<double> cumulativeProbabilities;
    double probability = 0.0;
    //Distributions to randomly pick a leader and rnadomly pick candidates from parties
    std::uniform_int_distribution<> leaders(0,2);
    std::uniform_int_distribution<> divisionCandidates(0,this->getNumOfDivisions()-1);
    //Calculating and storing the cumulative probabilities to determine which event occurs
    for(std::vector<double>::size_type i = 0; i < events.size();i++){
       probability += events[i].getOccurrence();
       cumulativeProbabilities.push_back(std::move(probability));
    }
    //Looping through each campaign day
    for(int i = 0; i < this->getNumOfDays(); i++){
        //Printing a formatted header to distinguish the election days from each other
        std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
        std::cout<<std::setfill(' ')<<std::setw(53)<<" "<<"Day "<<i+1<<std::endl;
        std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
        //Looping through the number of divisions
        for(int k = 0; k < this->getNumOfDivisions();k++){
            std::cout<<"----------Division "<<k+1<<"----------"<<std::endl;
            double occured = eventProbability(rndEng);
            //Checking for the events based on the cumulative probability
            for(std::vector<double>::size_type j = 0; j < events.size();j++){
                if(occured <= cumulativeProbabilities[j]){
                    //If the event involves the leader
                    if(events[j].getEventType() == "Leader"){
                        int index = leaders(rndEng);//random leader index
                        std::cout << "Breaking news involving the leader of the "<<this->getParties()[index].getPartyName()<<"."<<std::endl;
                        std::cout << "Event: "<<events[j].getDescription()<<std::endl;
                        //Adjusting the leader's popularity
                        double currentPopularity = this->getParties()[index].getLeader().getPopularity();
                        double newPopularity = currentPopularity + changePopularity(rndEng);
                        if(newPopularity > 1){
                            this->getParties()[index].getLeader().setPopularity(1);
                        }
                        else{
                            this->getParties()[index].getLeader().setPopularity(newPopularity);
                        }
                        break;
                    }
                    //If the event involves a candidate
                    else if(events[j].getEventType() == "Candidate"){
                        int index = leaders(rndEng);
                        std::cout<<"Breaking news involving the candidate "<<this->getParties()[index].getCandidates()[k].getCandidateName()<<" of the "<<this->getParties()[index].getPartyName()<<"."<<std::endl;
                        std::cout << "Event: "<<events[j].getDescription()<<std::endl;
                        //If the AI Scandal occurs, decreasing the candidate's popularity
                        if(cumulativeProbabilities[j] == 0.5){
                            double currentPopularity = this->getParties()[index].getCandidates()[k].getPopularity();
                            double newPopularity = currentPopularity - changePopularity(rndEng);
                            if(newPopularity <= 0){
                                newPopularity = 0.01;
                            }
                            this->getParties()[index].getCandidates()[k].setPopularity(newPopularity);
                        }
                        //If the other event occurs increase the significance and measure of all stances for the candidate
                        else{
                            for(std::vector<Stance>::size_type l = 0;l < this->getParties()[index].getCandidates()[k].getStances().size();l++){
                                double currentSignificance = this->getParties()[index].getCandidates()[k].getStances()[l].getSignificance();
                                double currentMeasure = this->getParties()[index].getCandidates()[k].getStances()[l].getMeasure();
                                double newSignificance = currentSignificance + changeStances(rndEng);
                                double newMeasure = currentMeasure + changeStances(rndEng);
                                if(newSignificance > 1){
                                   newSignificance = 1;
                                }
                                if(newMeasure > 1){
                                    newMeasure = 1;
                                }
                                this->getParties()[index].getCandidates()[k].getStances()[l].setSignificance(newSignificance);
                                this->getParties()[index].getCandidates()[k].getStances()[l].setMeasure(newMeasure);
                            }
                        }
                        break;
                    }
                    //If the event involves a division
                    else if(events[j].getEventType() == "Division"){
                        std::cout<<"Breaking news coming from "<<this->getDivisions()[k].getDivisionName()<<"."<<std::endl;
                        std::cout << "Event: "<<events[j].getDescription()<<std::endl;
                        //Adjusting the division k's stances
                        for(std::vector<Stance>::size_type l = 0; l < this->getDivisions()[k].getDivisionStances().size();l++){
                            double currentMeasure = this->getDivisions()[k].getDivisionStances()[l].getMeasure();
                            double currentSignificance = this->getDivisions()[k].getDivisionStances()[l].getSignificance();
                            double newMeasure = currentMeasure - changeStances(rndEng);
                            double newSignificance = currentSignificance - changeStances(rndEng);
                            if(newMeasure <= 0){
                                newMeasure = 0.01;
                            }
                            if(newSignificance <= 0){
                                newSignificance = 0.01;
                            }
                            this->getDivisions()[k].getDivisionStances()[l].setSignificance(newSignificance);
                            this->getDivisions()[k].getDivisionStances()[l].setMeasure(newMeasure);
                        }
                        break;
                    }
                }
                else if(occured > 0.8){
                    //If no event happens this message is displayed
                    std::cout <<"No news regarding the political campaign and national issues."<<std::endl;
                    break;
                }
            }
            std::cout<<"\n";
        }
        this->partyReport(); //Display each party's information at the end of the day
        this->nationReport(); //Display each divisno's information at the end of the day
    }
}

void Campaign::results(){
    //Printing a formatted header to distinguish the election day from other functions of the program
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(63)<<"Election Day"<<std::endl;
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    //declaring local int variables to store the socores for each party
    int strawScores = 0, redScores = 0, crossScores = 0;
    //Obtaining the coefficients from the election day class
    double A = this->getElectionDay().getCoefficients()[0];
    double B = this->getElectionDay().getCoefficients()[1];
    double C = this->getElectionDay().getCoefficients()[2];
    //Looping through each division to calculate each candidate's final result and increment a party's score based on the winner
    for(int i = 0; i < this->getNumOfDivisions();i++){
        std::vector<Candidate> divisionCandidates = this->getCandidatesInDivision(i);
        double victor = -1;
        std::string winningParty;
        std::cout<<"----------Division "<<i+1<<"----------"<<std::endl;
        //Looping through each candidate of division to calculate their result
        for(std::vector<Candidate>::size_type j = 0; j < divisionCandidates.size();j++){
            std::vector<Stance> candidateStances = divisionCandidates[j].getStances();
            std::vector<Stance> divisionStances = this->getDivisions()[i].getDivisionStances();
            double avgCosine = 0.0;
            //For each candidate we obtain their stances' sigificance and measure to calculate the average cosine similarity
            for(std::vector<Stance>::size_type k = 0; k < candidateStances.size();k++){
                double x1 = candidateStances[k].getSignificance();
                double x2 = candidateStances[k].getMeasure();
                double y1 = divisionStances[k].getSignificance();
                double y2 = divisionStances[k].getMeasure();

                double numerator = (x1 * y1) + (x2 * y2);
                double denominator = sqrt(x1 * x1 + x2 * x2) * sqrt(y1 * y1 + y2 * y2);
                double cosineSimilarity = numerator / denominator;

                avgCosine += cosineSimilarity;
            }
            avgCosine /= candidateStances.size();
            double stancePopulationFactor = avgCosine * this->getDivisions()[i].getPopulation();
            double score = A * stancePopulationFactor + B * this->getDivisions()[i].getPopulation() + C * this->getParties()[j].getLeader().getPopularity();
            std::cout<<"Candidate "<<divisionCandidates[j].getCandidateName()<<" from the "<<divisionCandidates[j].getPartyName()<<" has a score of "<<score<<std::endl;
            //Determining the winner of the division by storing the highest avgCosine value in score
            if(score > victor){
                victor = score;
                winningParty = divisionCandidates[j].getPartyName();
            }
        }
        //Incrementing the party based on the winning party
        if(winningParty == "Straw Hat Party"){
            strawScores++;
        }
        else if(winningParty == "Red Haired Party"){
            redScores++;
        }
        else if(winningParty == "Cross Guild Party"){
            crossScores++;
        }
        std::cout<<"\nWinner in "<<this->getDivisions()[i].getDivisionName()<<" is from "<<winningParty << " with a score of "<<victor<<std::endl;
        std::cout<<"\n";
    }
    //Displaying the final scores of each party
    std::cout<<"\n----------Final Scores----------"<<std::endl;
    std::cout<<"Straw Hat Party: "<<strawScores<<std::endl;
    std::cout<<"Red Haired Party: "<<redScores<<std::endl;
    std::cout<<"Cross Guild Party: "<<crossScores<<std::endl;
    std::cout<<"\n";
    std::vector<int> scores;
    scores.push_back(std::move(strawScores));
    scores.push_back(std::move(redScores));
    scores.push_back(std::move(crossScores));
    int highestScore = 0, secondScore = 0;
    Party winner = this->getParties()[0];
    Party runnerup = this->getParties()[0];
    //Determining the winner and checking if there is a hung parliament
    for(std::vector<int>::size_type i = 0; i < this->getParties().size();i++){
        if(scores[i] >= highestScore){
            secondScore = highestScore;
            runnerup = winner;
            winner = this->getParties()[i];
            highestScore = scores[i];
        }
    }
    //If the highestScore and secondScore are not equal there is no hung parliament
    if(highestScore != secondScore){
        std::cout<<"The party with the highest score is "<<winner.getPartyName()<<" with a score of "<<highestScore<<"."<<std::endl;
        std::cout<<winner.getLeader().getLeaderName()<<" rules the country.";
    }
    else{
        std::cout<<"There is a hung parliament between multiple parties as they got the same amount of scores. "<<std::endl;
    }
    std::cout<<"\n";
}

void Campaign::displayIssues(){
    //Printing a formatted header to distinguish the issues from other functions of the program
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(49)<<" "<<"National Issues"<<std::endl;
    std::cout<<std::setfill('=')<<std::setw(120)<<"="<<std::endl;
    //Looping through each issue and printing it
    for(std::vector<Issue>::size_type i = 0; i < this->getIssues().size();i++){
        std::cout<<"Issue "<<i+1<<":"<<std::endl;
        std::cout<<this->getIssues()[i].getIssueDescription()<<"\n"<<std::endl;
    }
}

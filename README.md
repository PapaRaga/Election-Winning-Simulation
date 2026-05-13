# Election Campaign Simulator

A C++ Object-Oriented Programming project that simulates a national election campaign across multiple electoral divisions.  
The simulation models political parties, leaders, candidates, public opinion, campaign events, and election results using probabilistic and mathematical calculations.

This project combines:
- Object-Oriented Programming
- Random event simulation
- Political campaign modelling
- Statistical calculations
- Election result analysis

---

## Features

### Political Campaign Simulation
- Simulates multi-day election campaigns
- Supports multiple electoral divisions
- Generates dynamic campaign events
- Models public opinion changes over time

### Political Parties
Three political parties are included:
- Straw Hat Party
- Red Haired Party
- Cross Guild Party

Each party contains:
- A leader
- Multiple candidates
- Unique political stances

### National Issues
The simulator models several political issues including:
- Global Warming
- Rights of Pets
- Quality Education
- Public Health
- Infrastructure

### Electoral Divisions
Each division contains:
- Population values
- Public stances on issues
- Election scoring factors

### Random Campaign Events
The system randomly generates events such as:
- Leader popularity boosts
- Candidate scandals
- Policy platform changes
- Division dissatisfaction events

### Election Result System
- Calculates candidate scores
- Uses cosine similarity for political alignment
- Determines division winners
- Detects hung parliaments
- Declares overall election winner

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (`vector`, `string`)
- Random Number Generation
- Mathematical Modelling
- Cosine Similarity Calculations

---

## Object-Oriented Concepts Used

- Classes and Objects
- Constructors
- Encapsulation
- Composition
- Inheritance
- Vectors and Dynamic Data Structures
- Modular Programming
- Getter and Setter Methods

---

## Mathematical Concepts

The election outcome uses:
- Cosine Similarity
- Weighted Scoring Systems
- Random Probability Distributions
- Statistical Modelling

### Election Score Formula

Candidate scores are influenced by:
- Political stance similarity
- Division population
- Leader popularity

---

## Project Structure

```bash
.
├── main.cpp
├── header.h
├── implementation.cpp
├── campaign.cpp
└── README.md

#pragma once
#include <iostream>
// #include "interpreter.h"
// #include "parser.h"
#include "Relation.h"
#include<string>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;





class Database {

private:
    //think of RELATIONS as "TABLES"
    //TUPLES are FACTS (or ROWS)
    map<string, Relation> relations;
    

public:
    Database(){}
     
    
    void ADD_Relation(Relation newRelation){
        //Relation is already created, so add ROW(name, item) to map
        //for loop for how big the maps is? maybe
        this->relations[newRelation.getName()] = newRelation;
    }
    Relation& GetRelation(string relationName) {
        return this->relations[relationName];
    }
    Relation GetRelationCopy(string relationName) {
        return this->relations[relationName];
    }
    //to get the rows of tuples and its name 
    Relation& GetTuple(string name, string parameters) {
        return this->relations[name, parameters];
        
    }
    const map<string, Relation>& a_getRelations() const {
        return relations;
    }
    
    
    
    //look up making an object, speaking of relation, make a constructor that takes a relation
    //predicate.name (name that points to a relation)


};
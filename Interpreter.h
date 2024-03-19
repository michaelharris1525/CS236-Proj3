#include <iostream>
#include "parser.h"
#include "Database.h"
// #include "Relation.h"
// #include "Tuple.h"
#include<string>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <map>
// #include <stdexcept> 
// #include <ostream>
// #include <string>
// #include <sstream>
using namespace std;

//make a Database object and make a database class

class interp {

private:
    c_datalogProgram program;
    Database database;

public:

    interp(const c_datalogProgram& program) : program(program) {}

    // void interpreter(c_datalogProgram program) {
    //     this->program = program;
    // }
    bool check_constant_or_not(string parameter) {
        if(parameter[0] == '\'') {
            return true;
        }
        else {
            return false;
        }
    }

    void print_relation() {
        const map<string, Relation> map = database.a_getRelations();
        // stringstream out;
        for(const auto& entry : map) {
            cout << "Relation Name:" << entry.first << endl;
            const Relation& relation = entry.second;
            cout << relation.toString() << endl;
        }
        // return out.str();
    }

    void i_schemes() {
        //Loop through each of the schemes, 
        //create a empty relation where the attributes of the relations are the parameters of the schemes, and the name of my relation is the name of my scheme
        //create an empty relation
        vector<c_Predicate> schemes = program.v_schemes;
        //for loop through each scheme and possible name and putting it as a datamember of database
        for(c_Predicate scheme: schemes) {
            string name = scheme.name;
            Scheme header_scheme = scheme.parameters;
            Relation default_relation = Relation(name, header_scheme);
            database.ADD_Relation(default_relation);
            //now I have an empty table 
        }
    }
    
    
 void i_facts() {
        //TUPLES = ROWS
        //loop through facts and just add them to their appropriate table
        
        vector<c_Predicate> vi_facts = program.v_facts;
        // vector <string> sf_parameters = fact.parameters;
        for(c_Predicate fact : vi_facts) {
            //get the table
            string name = fact.name;
            Relation current_rel = database.GetRelation(name);
            //looping through each Fact to get the parameters to a string sf= string fact               //get the parameters (attributes) from the fact and add to the tuple object
            vector <string> sf_parameters = fact.get_Parameters();
            Tuple temp = Tuple(sf_parameters);
            //add tuple to the relation
            current_rel.addTuple(temp);
             //add the relation back to database
            database.ADD_Relation(current_rel);
        }
        
    }


    //psuedo code for part 2
    /*
    //      Relation current_rel = database.GetRelation(name);
            Relation currentRel = database.getRelation(name))
            Tuple temp;
            For each parameter in fact {
                temp.addvalue(paramter.name)
            }
            currentRel.addTuple(temp);
            current_rel.addTuple(temp);
            Add relation back into database
           
            database.ADD_Relation(current_rel);
    */

    //step 2 void interpretFacts() {}
    /*for(Predicate fact : program.GetFacts()){
        each fact is a row in a relation/table called a tuple
        ex:snap("1","2","3","4")
        will add the row 1,2,3,4, into the table snap in the database

        steps
        1. get the table named snap by reference 
        from the database(hint: use the fact's name as key to the database's relation map)
        2.turn the parameters into a tuple and add it to the 'snap' relation.
    }*/


    /*
        ex:
        Looking at relation name SK 
        Looking for all tuples 
        select, project, and rename
    
    */


     void i_queries() {
        vector<c_Predicate> queries = program.v_queries;
        vector<string> parameter_Qstrings;
        vector<string> parameter_facts;
        map<string, int> map_keys; 
        for(c_Predicate query: queries) {
            string name = query.name;
            //copy of the relation in the database 
            Relation current_rel = database.GetRelation(name);
            vector<int>project_indices;
            vector<string>renamed_values;
            
            for(unsigned int i = 0; i< query.get_Parameters().size(); i++) {
                //get all parameters of the query
                string parameter = query.get_Parameters()[i];
                parameter_Qstrings.push_back(parameter); 
                
            }
            for(unsigned int i = 0; i < parameter_Qstrings.size(); i++) {
                //if constant or parameter in relation(value from Tuple) is equal
                //select type 1
                //constant == ' ' or " "
                if(check_constant_or_not(parameter_Qstrings.at(i))) {
                    current_rel = current_rel.select(i, parameter_Qstrings.at(i));
                }
                //variable
                else {
                    if(map_keys.count(parameter_Qstrings.at(i)) == true) {
                        //if variable == variable (like X == X) 
                        //then do a select Type 2
                        current_rel = current_rel.select_2(i, i);
                    }
                    else {
                        //else its a variable like "x or Y"
                        map_keys[parameter_Qstrings.at(i)] = i;
                        project_indices.push_back(i);
                        renamed_values.push_back(parameter_Qstrings.at(i));
                    }
                
                //2 more conditional statements inside the else statement
                
                }
                //when do I do this? Example?
                // current_rel.rename()
                // current_rel.project()
               
            }
            //mark for project and Rename
            current_rel = current_rel.project(project_indices);
            current_rel.rename(renamed_values);

            database.ADD_Relation(current_rel);
            // print_relation();

        }
    }
    

    //step 3 void interpretQueries() {}
    /*
        for(Predicate query: program.GetQueries(){
            -each query gets a copy of the relation in the database with the 
            same name as the query. Interpreting the query means understanding what the query's parameters want
            from this relation and morphing the relation copy into a smaller resulting relation using select, project, and rename (functions you need to implement in the relations class)
            steps
            1. if the parameters[i] is a constant, select(type 1) that parameter value out of the relation.
            2. If the paramters[i] is a variable, have we seen the same variable before in this same query? if so 
            select(type 2) matching values in 2 columns of relation
        })
    */
    
};
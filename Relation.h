// #pragma once
#include "Scheme.h"
#include "Tuple.h"
#include<string>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
// #include <stdexcept> 
// #include <ostream>
#include <string>
#include <sstream>
// #include <map>
using namespace std;

class Relation {

 private:

  string name;
  Scheme scheme;
  set<Tuple> tuples;

 public:
  //example: Trainer("squirtle","Ivey","Char");
    Relation(const string& name, const Scheme& scheme)
      : name(name), scheme(scheme) { }

    Relation() {}

  //should I make a getTuple function here instead?
    
    void addTuple(const Tuple& tuple) {
      tuples.insert(tuple);
    }

    string getName() const {
      return name;
    }

    string toString() const {
    stringstream out;
    for (const auto& tuple : tuples) {
        out << tuple.toString(scheme) << endl;
    }
    // add code to print the Tuples, one per line
    return out.str();
    }
    //type 1 select
    Relation select(int index, const string& value) const {
        Relation result(name, scheme);
        for(const Tuple& tuple: tuples) {
            if(tuple.at(index) == value){
                result.addTuple(tuple);
            }
        }
        // add tuples to the result if they meet the condition
        return result;
    }
  //type 2 select X, X (give it 2 indexes), go through each row/tuple and 
  // if === you add them
    Relation select_2(int index, int index2) {
      Relation result(name, scheme);
      for(const Tuple& tuple: tuples) {
        //if tuples are the same at same index
        if(tuple.at(index) == tuple.at(index2)) {
          result.addTuple(tuple);
        }
      }
      return result;
    }


  //make project function
    Relation project(vector<int> list_columns) {
      vector<string> temp_schemes;
      //how to call default constructor and set vector or parameters of constructor
      Scheme new_scheme(temp_schemes);
      vector<string> empty_row;
      Tuple tuple_row(empty_row);
      Relation result(name, new_scheme);
      for(auto index : list_columns) {
        //schemes/title headers
        //add the header of that index to the new one
        new_scheme.push_back(this->scheme.names.at(index));
        // result.addScheme_pushback(scheme.at(index));
      }
      for(const auto& tuple: tuples) {
        vector<string> new_row;
        for(auto index : list_columns) {
          new_row.push_back(tuple.at(index));
          // tuple_row.at(index).insert()
        }
        result.addTuple(Tuple(new_row));
      }

      return result;
    }

 //make re-name function
    void rename(Scheme new_header) {
      scheme = new_header;
    }

    string print_relation() const {
      return toString();
    }



 

  // static Relation createEmptyRelation(const Scheme& scheme) {
  //       vector<string> parameters;
  //       for (unsigned i = 0; i < scheme.size(); ++i) {
  //           parameters.push_back(scheme.at(i));
  //       }
  //       return Relation("DefaultRelationName", Scheme(parameters));
  // }
  

};











// //make a map key value to loop through with the name and all values in that column
//       map<string, vector<string>> key_title_column;
//       //staring at index zero, getting the list of values
//       for(int i = 0; i < result.scheme.getScheme().size(); i++) {
//         string key_value = result.scheme.getScheme().at(i);
//         key_title_column.insert(make_pair(key_value, vector<string>()));


//         //working with the relation/rows of tuples
//         //auto already iterates on its own
//         auto i_tuple = tuples.begin();
//         while(i_tuple != tuples.end()) {
//           Tuple tuple_value = *i_tuple;
//           key_title_column.at(key_value).push_back(tuple_value.at(list_columns.at(i)));
//         }

//       }
//       //iterating through the tuples to join the tuples together, they're separate still
//       for(int z = 0; z <tuples.size(); z++) {
//         //iterating through the map you made to reconstruct the tuples
//         map<string, vector<string>>:: iterator it_map;
//         for(it_map = key_title_column.begin(); it_map != key_title_column.end(); it_map++){
//           string s_header;
//           vector<string>second_values_from_map;
//           // second_values_from_map.push_back(it_map.second);

         
          

//         }
//       }
#include <iostream>
#include "scanner.h"
#include "parser.h"
#include "Interpreter.h"
#include <vector>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include <map>

int main(int argc, char* argv[]) {
//local testing with custom input
  // Scanner s = Scanner("  :-  ,  \n + \"Jack Black\" :- \n () Schemes \n jakc1 :- ");
  // vector <Token> t = s.scanToken();
  // for (Token &t : t) {
  //   cout << t.toString() << endl;
  // }

   //testing with files
   //Read the contents of the input file into a string
    ifstream inFile(argv[1]);
    /*int number_tokens = 0;*/
    stringstream buffer;
    buffer << inFile.rdbuf();
    string input = buffer.str();

    // Close the input file
    inFile.close();

    //  Create a Scanner object and scan the input string
     Scanner scanner(input);
     vector<Token> tokens = scanner.scanToken();
     vector<Token> notTokens;
     for (size_t i = 0; i < tokens.size(); i++) {
         if (tokens.at(i).getType() != COMMENT) {
          notTokens.push_back(tokens[i]);
         }
     }
         

    // // Output the scanned tokens
    // for (const Token& token : tokens) {
    //     cout << token.toString() << endl;
    //     number_tokens++;
    // }
    // cout << "Total Tokens = " << number_tokens << endl;




//Parsing all tokens
    Parser p = Parser(notTokens);
    p.parse();

   

    interp object_hold_data = interp (p.get_datalogProgram());
    

  //Tuple_tostring practice
  // vector<string> names = { "ID", "Name", "Major" };

  // Scheme scheme(names);

  // vector<string> values[] = {
  //   {"'42'", "'Ann'", "'CS'"},
  //   {"'32'", "'Bob'", "'CS'"},
  //   {"'64'", "'Ned'", "'EE'"},
  //   {"'16'", "'Jim'", "'EE'"},
  // };

  // for (auto& value : values) {
  //   Tuple tuple(value);
  //   cout << tuple.toString(scheme) << endl;
  // }

  // vector<string> names = { "ID", "Name", "Major" };
  // c_datalogProgram datalogProgram; 
  // Database object_tocall;
  // vector<c_Predicate> list_schemes = datalogProgram.v_schemes;
  

  // for(c_Predicate &scheme: list_schemes) {
  //   vector<string> names = scheme.get_Parameters();
  //   Scheme name_scheme = Scheme(names);
  //   Relation current_rel(scheme.p_getName(),name_scheme); 
  //   object_tocall.ADD_Relation(current_rel);
  // }

 
  // vector<string> values = 

  // for (auto& value : values) {
  //   Tuple tuple(value);
  //   cout << tuple.toString(scheme) << endl;
  //   relation.addTuple(tuple);
  // }

  // cout << "relation:" << endl;
  // cout << relation.toString();

  // Relation result = relation.select(2, "'CS'");

  // cout << "select Major='CS' result:" << endl;
  // cout << result.toString();
  object_hold_data.i_schemes();
  object_hold_data.i_facts();
  object_hold_data.i_queries();
  object_hold_data.print_relation();


  //  object_hold_data.database.GetRelation();

  // Database myDatabase;

  //  // Relation r = Relation(r.)
  //  for (const auto& entry : myDatabase.a_getRelations()) {
  //       const Relation& relation = entry.second;
  //       // Print the name of the relation
  //       string name = relation.getName();
  //       cout << "Relation: " << name << endl;
  //       // Print the full relation
  //       cout << relation.toString() << endl;
  //   }


}
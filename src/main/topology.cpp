#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "topology.h"

using namespace std;

static void erase_char_from_string(string *str, char ch);

static void strip_comments(string *str);

<<<<<<< HEAD
=======
static string strip_whitespace_from_tags(string str);

>>>>>>> 45af88de45c5b4714f81379de640dab556d3e9af
Topology parse_topology_file(string topology_path){
	std::ifstream top_file(topology_path.c_str(), std::ifstream::in);
	std::stringstream buffer;
	
	if(top_file.is_open()){
		buffer << top_file.rdbuf();
	}else{
		throw 8;
	}
	
<<<<<<< HEAD
	string full_topology(buffer.str());
=======
	std::string full_topology(buffer.str());
>>>>>>> 45af88de45c5b4714f81379de640dab556d3e9af

	Topology topology;

	erase_char_from_string(&full_topology, '\n');
	erase_char_from_string(&full_topology, '\r');
	erase_char_from_string(&full_topology, '\t');
	
	strip_comments(&full_topology);
<<<<<<< HEAD
		
	size_t start_tag_loc = full_topology.find(FLAG_START);
	size_t end_tag_loc = full_topology.find(FLAG_END) + sizeof(FLAG_END) - 1;
	string flag_str = full_topology.substr(start_tag_loc, end_tag_loc - start_tag_loc);
	string rest_of_top = full_topology.substr(end_tag_loc + 1, full_topology.length() - end_tag_loc - 1 );
	string flag_field = rest_of_top.substr(0, rest_of_top.find(FLAG_START));
	
	do {
		
		if(end_tag_loc == string::npos){
			break;
		}
		
		flag_str = rest_of_top.substr(start_tag_loc, end_tag_loc);
		rest_of_top = rest_of_top.substr(end_tag_loc, rest_of_top.length());
		flag_field = rest_of_top.substr(0, rest_of_top.find(FLAG_START));


		start_tag_loc = rest_of_top.find(FLAG_START);
		end_tag_loc = rest_of_top.find(FLAG_END) + sizeof(FLAG_END) - 1;
			
		cout << flag_field << endl;
	} while (start_tag_loc != std::string::npos);

=======
	
	strip_whitespace_from_tags(full_topology);

	cout << full_topology << endl;	
	
>>>>>>> 45af88de45c5b4714f81379de640dab556d3e9af
	return topology;
}

static void erase_char_from_string(string *str, char ch){
	str->erase(std::remove(str->begin(), str->end(), ch), str->end());
}

static void strip_comments(string *str){
	size_t comment_loc = str->find(TAG_START_COMMENT);
	size_t end_comment_loc = str->find(TAG_END_COMMENT) + sizeof(TAG_END_COMMENT) - 1;
	
	while(comment_loc != std::string::npos){
<<<<<<< HEAD
		str->erase(comment_loc, end_comment_loc - comment_loc);
		comment_loc = str->find(TAG_START_COMMENT);
		end_comment_loc = str->find(TAG_END_COMMENT) + sizeof(TAG_END_COMMENT) - 1;
		
	}
=======
		str->erase(comment_loc, end_comment_loc);
		comment_loc = str->find(TAG_START_COMMENT);
		end_comment_loc = str->find(TAG_END_COMMENT);
	}
}

static string strip_whitespace_from_tags(string str){

	size_t start_tag_loc = str.find(FLAG_START);
	size_t end_tag_loc = str.find(FLAG_END) + sizeof(FLAG_END) - 1;
	
	string sub_string;
	
	while(start_tag_loc != std::string::npos){
		sub_string = str.substr(start_tag_loc, end_tag_loc - start_tag_loc);
		erase_char_from_string(&sub_string, ' ');
		
		start_tag_loc = str.find(FLAG_START);		
		end_tag_loc = str.find(FLAG_END) + sizeof(FLAG_END) - 1;
		//temp
		break;
	}
	return str;

>>>>>>> 45af88de45c5b4714f81379de640dab556d3e9af
}

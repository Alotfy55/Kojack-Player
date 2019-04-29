#pragma once

#include "GUI Functions.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio> 
#include <vector>
#include <map>
#include <Windows.h>
#include <fstream>
#include <array> 
#include <set>
#include <random>       
#include <chrono> 
#include <conio.h>
#define directory "C:\\Users\\lenovo\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\resources/"
#define users_directory "C:\\Users\\lenovo\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\Data/" 
#define Imgs_directory "C:\\Users\\lenovo\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\Imgs/"
#define max_numsongs 10000
#define Low_rating_activator 2
#define Highest_rating 5


using namespace std;
using namespace sf;


struct song
{
	string name;
	string genre;
	string album;
	string artist;
	int year;
	int rating = 0;
	bool display = true;
}song_data[max_numsongs];


struct user
{
	string name;
	string password;
}users_data[16];


//// global variables  ///


//// number of users which will be read from file 
int NumUsers = 0;
int index_of_playing_song;
int shuffled[max_numsongs];
bool shufflle = false;
string current_user;

////vectors used a return in certain functions 
vector<string> songs;
vector<string> sorted_songs;
vector <string> songs_by_a_default_thing;
vector<string> searching_results;
/////
int is_songs_sorted = 0;
bool playing = false;
int showanythingiwant;
sf::Music music;
//// all songs in the folder
int number_of_current_songs = 0;
int rating = 0;
string playing_song_name = "";
string userinput_search = "";
sf::Vector2f mouse_position;
string mod; 
int searchicator = 1 ;



////// Player FUCNTIONS Declerations /////***
void get_all_files_names_within_folder(string folder);
void playMusic(const std::string& filename);
vector<string> View_song(int choice, string name);
void read_users();
bool signup(string username, string password);
bool login(string user, string password);
void READ_RATING();
void Read_MetaData();
vector<string> View_all(int choice);
void shuffle(vector<string>ToShuffle);
void check_order(int& index_of_playing_song);
vector<string> sorting(int x);
void rate(string name, int& rating);
void get_Rating_for_current_song(string song_name);
vector<string>search_display(string searched, int choice);

////// Player FUCNTIONS Definitions /////***

void get_all_files_names_within_folder(string folder)
{
	// Reads all .wav files in specific folder
	int i = 0;
	string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				song_data[i].name = fd.cFileName;
				// erases .wav from songs title 
				song_data[i].name.erase(song_data[i].name.end() - 4, song_data[i].name.end());
				songs.push_back(song_data[i].name);
				i++;
				number_of_current_songs++;
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}

void playMusic(const std::string& filename)
{
	if (!music.openFromFile(directory + filename + ".wav"))
		return;
	music.play();
	playing = true;
}

void read_users()
{
	fstream users;
	users.open("usersInfo.txt");
	users >> NumUsers;
	users.ignore();
	for (int i = 0; i < NumUsers; i++)
	{
		getline(users, users_data[i].name);
		getline(users, users_data[i].password);
	}

}

bool signup(string username, string password)
{
	bool taken = false;

	for (int i = 0; i < NumUsers; i++)
	{
		if (username == users_data[i].name)
		{
			
			taken = true;
		}
	}
	if (!taken)
	{

		
	}
	else {
		return false;
	}


	NumUsers++;

	// updates user info file
	fstream users;
	users.open("usersInfo.txt", ios::out | ios::trunc);
	users << NumUsers << endl;
	users << username << endl;
	users << password << endl;
	if (NumUsers > 1)
	{
		for (int i = 0; i < NumUsers; i++)
		{
			users << users_data[i].name << endl;
			users << users_data[i].password << endl;
		}
	}
	current_user = username;
	// create rating file 
	ofstream new_file;
	new_file.open(users_directory + username + ".txt");
	
		
	return true;

}

bool login(string user, string password)
{
	bool Logedin = false;
	while (true)
	{
		
		for (int i = 0; i < NumUsers; i++)
		{
			if (user == users_data[i].name)
			{
				
				
				if (password == users_data[i].password)
				{
					Logedin = true;
					current_user = users_data[i].name;


				}
			}
		}
		if (Logedin)
			return true;
		else {
			return false;
			
		}

	}
		system("cls");
}

void READ_RATING()
{
	fstream Rating_file;
	Rating_file.open(users_directory + current_user + ".txt");
	int counter = 0;
	for (int i = 0; i < number_of_current_songs; i++)
	{
		Rating_file >> song_data[i].rating;
		if (song_data[i].rating <= Low_rating_activator && song_data[i].rating > 0)
		{
			song_data[i].display = false;
			while (true)
			{
				if (song_data[i].name == songs[counter])
				{

					songs.erase(songs.begin() + counter);
					break;
				}
				counter++;
			}
		}
	}
	Rating_file.close();

}

void Read_MetaData()
{
	fstream fs;
	fs.open("data.txt");
	for (int i = 0; i < number_of_current_songs; i++)
	{
		getline(fs, song_data[i].artist);
		getline(fs, song_data[i].genre);
		getline(fs, song_data[i].album);
		fs >> song_data[i].year;

	}
}

vector<string> View_all(int choice)
{
	set<string> ones;
	vector<string>to_be_shown;
	int counter = 0;
	to_be_shown.clear();
	ones.clear();
	for (int i = 0; i < number_of_current_songs; i++) {
		if (choice == 1) {
			ones.insert(song_data[i].artist);
		}
		else if (choice == 2)
			ones.insert(song_data[i].genre);
		else if (choice == 3)
			ones.insert(song_data[i].album);
	}
	for (auto i : ones) {
		to_be_shown.push_back(i);
	}
	
	return to_be_shown;
}

vector<string> View_song(int choice, string name)
{
	set<string> ones;
	vector<string>to_beshown;
	to_beshown.clear();
	ones.clear();
	for (int i = 0; i < number_of_current_songs; i++) {
		if (choice == 1 && name == song_data[i].album) {
			ones.insert(song_data[i].name);
		}
		else if (choice == 2 && name == song_data[i].artist)
			ones.insert(song_data[i].name);
		else if (choice == 3 && name == song_data[i].genre)
			ones.insert(song_data[i].name);
	}
	for (auto i : ones) {
		to_beshown.push_back(i);
	}

	return to_beshown;
}

void shuffle(vector<string>ToShuffle)
{
	array <int, max_numsongs> shuffled_order = {};


	// intializing the array with values from 1 to the number of songs in the folder
	for (int i = 0; i <= ToShuffle.size() - 1; i++)
	{
		shuffled_order[i] = i;
	}
	for (int i = ToShuffle.size() - 1; i >= 0; i--)
	{
		int j = rand() % (ToShuffle.size() - 1);
		int tmp = shuffled_order[j];
		shuffled_order[j] = shuffled_order[i];
		shuffled_order[i] = tmp;
	}
	for (int i = 0; i < ToShuffle.size(); i++)
	{
		shuffled[i] = shuffled_order[i];
	}
}

void check_order(int& index_of_playing_song) {
	if (index_of_playing_song < 0) {
		index_of_playing_song = songs.size() - 1;
	}
	if (index_of_playing_song > songs.size() - 1) {
		index_of_playing_song = 0;
	}
}

vector<string> sorting(int x)
{



	vector<string> names;
	names.clear();


	if (x == 1)
	{
		for (int i = Highest_rating; i >= 0; i--) {
			for (int j = 0; j < number_of_current_songs; j++) {
				if (song_data[j].rating == i) {
					if (song_data[j].rating > 0 && song_data[j].rating < Low_rating_activator)
						continue;
					names.push_back(song_data[j].name);

				}
			}
		}
	}
	else if (x == 2)
	{
		for (int i = 0; i <= Highest_rating; i++) {
			for (int j = 0; j < number_of_current_songs; j++) {
				if (song_data[j].rating == i) {
					if (song_data[j].rating > 0 && song_data[j].rating < Low_rating_activator)
						continue;
					names.push_back(song_data[j].name);

				}
			}
		}
	}



	return names;

}

void rate(string name, int& rating)
{
	if (rating < 2) {
		music.openFromFile("Tda5ol.wav");
		music.play();
	}
	fstream Rating_file;
	Rating_file.open(users_directory + current_user + ".txt");
	for (int i = 0; i < number_of_current_songs; i++)
	{
		if (name == song_data[i].name)
		{
			song_data[i].rating = rating;
			Rating_file << song_data[i].rating << endl;
			
		}
		else
		{
			Rating_file << song_data[i].rating << endl;
		}

	}
	Rating_file.close();
}

void get_Rating_for_current_song(string song_name) {

	for (int j = 0; j < number_of_current_songs; j++) {
		if (song_name == song_data[j].name) {
			rating = song_data[j].rating;
		}
	}

}

vector<string>search_display(string searched, int choice)
{
	int year = 0;
	if (choice == 3) {
		for (int i = 0; i < searched.size(); i++) {
			year *= 10;
			year += (searched[i] - '0');
		}
	}
	vector<string> ToPlay;
	ToPlay.clear();
	for (int i = 0; i < number_of_current_songs; i++)
	{
			switch (choice)
			{

			case 0:

				if (song_data[i].name.find(searched) < song_data[i].name.size())
				{
					ToPlay.push_back(song_data[i].name);


				}
				break;
		case 1:
			
				if (song_data[i].album.find(searched) < song_data[i].album.size())
				{
					ToPlay.push_back(song_data[i].name);

				}
			
				break;
		case 2:
			
				if (song_data[i].artist.find(searched) != -1)
				{
					ToPlay.push_back(song_data[i].name);

				}
			
				break;
		case 3:
			
				if (song_data[i].year == year)
				{
					ToPlay.push_back(song_data[i].name);

				}
			
				break;
		}
	}
	return ToPlay;
}
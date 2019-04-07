#pragma warning(disable : 4996) //Disables error (4996) bec it is just vs freaking on us  
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio> 
#include <vector>
#include <map>
#include <Windows.h>
#include <fstream>
#include <array>        
#include <random>       
#include <chrono> 
#include <conio.h>
#define directory "C:\\Users\\Owner\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\resources/"
#define max_numsongs 10000
using namespace std;
bool quit = false;
bool menu = false; 
struct song
{
	string name;
	string genre;
	string album;
	string artist;
	int year;
	int rating = 0;
}song_data[10000];

int shuffled[max_numsongs] , counter=0;

bool shufflle = false;

bool found = false;
vector<string> songs;
void get_all_files_names_within_folder(string folder);
void playMusic(const string& filename, int &play_num);
void list_display();
void playback(vector <string>names);
void shuffle(vector<string>ToShuffle); 
void check_order(int &i);
void Read_MetaData();
void sorting();
void find_by_name();
void find_by_genre();
void find_by_album();
void find_by_artist();
void find_by_year();
int begin(bool first);
void decision(int x);
void artist();
void genres();
void albums();
void search();
void rate(int x , string name);
void Low_Rating(int x);
void READ_RATING();

int main()
{
	// Welcome to main 
	bool first = true; 
	get_all_files_names_within_folder(directory);
	Read_MetaData();
	READ_RATING();
 	while (true)
	{
		system("cls");
		decision(begin(first));
		if (quit)
			break;
		first = false;
	}
	system("pause");
	return 0;
}
int begin(bool first)
{
	if (first) {
		cout << "Welcome in Kojack Player Thanks for using me " << endl;
		first = false; 
	}
	cout << "Press \n1 to view all songs in the system" << endl;
	cout << "2 to view all artists of the songs in the system\n3 to view all genres of the songs in the system" << endl;
	cout << "4 to view all albums in the system \n5 to search"<<endl;
	if (!shufflle)
		cout << "6 To enable Shuffle" << endl;
	else
		cout << "6 To disable Shuffle" << endl;
	int x;
	cin >> x;
	system("cls");
	return x;
}

void decision(int x)
{
	switch (x) {
	case 1: 
		list_display();
		break;
	case 2:
		artist();
		break;
	case 3:
		genres();
		break;
	case 4 :
		albums();
		break;
	case 5 :
		search();
		break;
	case 6:
		if (shufflle)
			shufflle = false;
		else
		{
			shufflle = true;
		}
		break;
	}
}

void artist()
{
	vector<string>artists;
	artists.clear();
	set<string> artist;
	for (int i = 0; i < songs.size(); i++) {
		artist.insert(song_data[i].artist);
	}
	int counter = 0;
	for (auto i : artist) {
		cout << counter + 1 << " ) " << i << endl;
		artists.push_back(i);
		counter++;
	}
	cout << "Please enter the number of the artist you want to listen to : ";
	int x; cin >> x;
	
	vector<string>plays;
	

	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].artist == artists[x-1])
		{
			plays.push_back(songs[i]);
		}
	}
	playback(plays);
}

void genres()
{
	vector<string>genre;
	genre.clear();
	set<string> genres;
	for (int i = 0; i < songs.size(); i++) {
		genres.insert(song_data[i].genre);
	}
	int counter = 0;
	for (auto i : genres) {
		cout << counter + 1 << " ) " << i << endl;
		counter++;
		genre.push_back(i);
	}
	cout << "Please enter the number of the genre you want to listen to : ";
	int x; cin >> x;

	vector<string>plays;


	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].genre == genre[x-1])
		{
			plays.push_back(songs[i]);
		}
	}
	playback(plays);
	system("pause");
}

void albums()
{
	vector<string>albums;
	albums.clear();
	set<string> album;
	for (int i = 0; i < songs.size(); i++) {
		album.insert(song_data[i].album);
	}
	int counter = 0; 
	for (auto i : album) {
		cout <<counter+1 <<" ) " << i << endl;
		counter++;
		albums.push_back(i);
	}
	cout << "Please enter the number of the album you want to listen to : ";
	int x; cin >> x;

	vector<string>plays;


	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].album == albums[x-1])
		{
			plays.push_back(songs[i]);
		}
	}
	playback(plays);
}


void shuffle(vector<string>ToShuffle)
{
	/* this function shuffles the indecies and put them in array named shuffled 
		then uses the array shuffled as an index to play music from the vector songs */
	array <int, max_numsongs> shuffled_order = {};


	// intializing the array with values from 1 to the number of songs in the folder
	for (int i = 1; i <= ToShuffle.size(); i++)
	{
		shuffled_order[i] = i;
	}
	// generating seed used to generate diffrent order every time
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
	 shuffle(shuffled_order.begin(), shuffled_order.end(), default_random_engine(seed));
	 
	 for (int i = 0; i < max_numsongs ; i++)
	 {
		 if (shuffled_order[i] != 0)
		 {
			 shuffled[counter] = shuffled_order[i] - 1;
			 counter++;
		 }
	 }
	
}

void list_display()
{
	for (int i = 1; i <= songs.size(); i++)
	{
		cout << i << " : " << song_data[i - 1].name << endl;
	}
	cout << endl << endl;
	cout << "Press 1 to play in normal order \nPress 2 to sort the list\nPress 3 to Return to Kojack Menu" << endl;
	int x; cin >> x;
	switch (x) {
	case 1:
		playback(songs);
		break;
	case 2:
		sorting();
		break;
	case 3 : 
		break;
	}
}

void playback(vector<string>names)
{
	system("cls");
	if (!shufflle) {
	for (int i = 0 ; i < names.size(); i++)
	{
		playMusic(names[i], i);
		check_order(i);
		system("cls");
		if (menu)
		{
			menu = false; 
			return;
		}
	}
	}
	else {
		shuffle(names);
		for (int i = 0; i < names.size(); i++)
		{
			system("cls");
			playMusic(names[shuffled[i]], i);
			check_order(i);
			if (menu)
			{
				menu = false;
				return;
			}
		}
	}
}

void check_order(int &i)
{
	// the final i in both cases will be incrmented in the for loop in the calling function

	// to play the first song after the last song
	if (i == songs.size() - 1)
	{
		i = -1;
	}
	// if you play the previous song while playing the first song in the list the i would be -2 
	else if (i == -2)
	{
		i = songs.size() - 2;
	}
}

void get_all_files_names_within_folder(string folder)
{
	// Reads all .wav files in specific folder
	string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) 
	{
				int i = 0;
		do 
		{
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
			{
				song_data[i].name = fd.cFileName;
				
				songs.push_back(fd.cFileName);
				i++;
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	for (int i = 0; i < songs.size(); i++)
	{
		song_data[i].name = songs[i];
	}
}

void READ_RATING()
{
	fstream Rating_file;
	Rating_file.open("Rating.txt");
	for (int i = 0; i < songs.size(); i++)
	{
		Rating_file >> song_data[i].rating ;
	}
	Rating_file.close();
}

void playMusic(const std::string& filename, int &play_num)
{
	// Load an ogg music file
	sf::Music music;
	if (!music.openFromFile(directory + filename))
		return;

	// Display music informations
	std::cout << filename << ":" << std::endl;
	std::cout << " " << music.getDuration().asSeconds() << " seconds" << std::endl;
	std::cout << " " << music.getSampleRate() << " samples / sec" << std::endl;
	std::cout << " " << music.getChannelCount() << " channels" << std::endl;
	
	// Play it
	music.play();
	// Loop while the music is playing
	cout << "Press p to pause , Press it again to play  \ns to stop  \nb backwards  \nr to Rate  \nm to return to main menu" << endl;
	while (music.getStatus() == sf::Music::Playing || music.getPlayingOffset().asSeconds() < music.getDuration().asSeconds())
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));
		if (music.getPlayingOffset().asSeconds() == music.getDuration().asSeconds())
			break;

		// Display the playing position
		std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        ";
		std::cout << std::flush;
		
		if (kbhit())
		{
			char x;
			if (cin >> x)
			{
				if (x == 'p' &&  music.getStatus() == sf::Music::Playing)
					music.pause();
				else if (x == 'p')
					music.play();
				else if (x == 'n')
				{
					//next
					return;
				}
				else if (x == 's' && music.getStatus() == sf::Music::Playing)
				{
					music.stop();
				}
				else if (x == 'b')
				{
					//b as in backwards 
					play_num-=2;
					return;
				}
				else if (x == 'r')
				{
					rate(play_num , filename );
				}
				else if (x == 'm')
				{
					menu = true; 
					break; 
				}
			
			}
		}
	}
	std::cout << std::endl << std::endl;
}

void Read_MetaData()
{
	fstream fs;
	fs.open("data.txt");
	for (int i = 0; i < songs.size(); i++)
	{
		getline(fs, song_data[i].artist);
		getline(fs, song_data[i].genre);
		getline(fs, song_data[i].album);
		fs >> song_data[i].year;
	}

}

void search()
{
	cout << flush << "Press \n1 To Search by name\n2 To Search by artist name\n3 To Search by Album\n4 To Search by genre\n5 To Search by year\n6 To Return to The Kojack Menu "<<endl;
	int n; cin >> n;
	switch (n)
	{
	case 1 :
		find_by_name();
		break;
	case 2 :
		find_by_artist();
		break;
	case 3 :
		find_by_album();
	case 4 :
		find_by_genre();
		break;
	case 5:
		find_by_year();
		break;
	case 6 :
		return;
	default:
			cout << "not valid input" << endl;
			return search();
			break;

	}

}

void rate(int x, string name)
{
	int rating;
	cout << "Enter Rating :";
	while (true)
	{
		cin >> rating;
		if (rating > 5 || rating < 0)
		{
			cout << "Invalid rating \nEnter Rating :";
		
		}
		else
		{
			if (rating < 2)
			{
				Low_Rating(x); //playsound !display
			}
			break;
		}
	}
	fstream Rating_file;
	Rating_file.open("Rating.txt");
	for (int i = 0; i < songs.size(); i++)
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

void Low_Rating(int x)
{

}

void find_by_name()
{
	cout << "Enter Song Name : ";
	string s;
	cin.ignore();
	getline(cin, s);
	if (s[0] >= 97 && s[0] <= 122)
		s[0] -= 32;

	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].name.find(s) < song_data[i].name.size())
		{
			cout << i << " ) " << song_data[i].name << endl;
			found = true;
		}
	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		char command; cin >> command;
		if (command == '1')
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
	}
	else
		cout << "Not Found!";
	system("pause");
}
void find_by_genre()
{
	cout << "Enter Genre : ";
	string s;
	cin.ignore();
	getline(cin, s);
	if (s[0] >= 97 && s[0] <= 122)
		s[0] -= 32;
	

	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].genre.find(s) < song_data[i].genre.size())
		{
			cout << i << " ) " << song_data[i].name << endl;
			found = true;
		}
	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		char command; cin >> command;
		if (command == '1')
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
		else
			cout << "Not Found!";
	}
	system("pause");
}
void find_by_album()
{
	cout << "Enter Album : ";
	string s;
	cin.ignore();
	getline(cin, s);
	
	if (s[0] >= 97 && s[0] <= 122)
		s[0] -= 32;
	


	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].album.find(s) < song_data[i].album.size())
		{
			cout << i << " ) " << song_data[i].name<<endl;
			found = true;
		}

	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		char command; cin >> command;
		if (command == '1')
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
	}
	else
		cout << "Not Found!";
	system("pause");
}
void find_by_artist()
{
	cout << "Enter Artist : ";
	string s;
	cin.ignore();
	getline(cin, s);
		if (s[0] >= 97 && s[0] <= 122)
			s[0] -= 32;
	
	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].artist.find(s) != -1)
		{
			cout << i << " ) "<< song_data[i].name<<endl;
			found = true;
		}

	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		char command; cin >> command;
		if (command == '1')
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
	}
	else
		cout << "Not Found!";
	system("pause");
}
void find_by_year()
{
	cout << "Enter Release Year : ";
	int s; cin >> s;
	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (song_data[i].year == s)
		{
			cout << i << " ) " << song_data[i].name<<endl;
			found = true;
		}
	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		char command; cin >> command;
		if (command == '1')
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
	}
	else
		cout << "Not Found!";

}

void sorting()
{
	vector<string> names;
	cout << "Enter\n1 to sort high to low\n2 to sort low to high :" ;
	int x, counter = 0; cin >> x;
	system("cls"); 
	if (x == 1)
	{
		for (int i = 5; i >= 0; i--) {
			for (int j = 0; j < songs.size(); j++) {
				if (song_data[j].rating == i) {
					cout << counter + 1 << " ) " << song_data[j].name << endl;
					names.push_back(song_data[j].name);
					counter++;
				}
			}
		}
	}
	else if (x == 2)
	{
		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j < songs.size(); j++) {
				if (song_data[j].rating == i) {
					cout << counter + 1 << " ) " << song_data[j].name << endl;
					names.push_back(song_data[j].name);
					counter++;
				}
			}
		}
	}
	cout << endl << endl;
	cout << "Press 1 to play in this order \nPress 2 to Return to Kojack Menu" << endl;
	int k; cin >> k;
	switch (k) {
	case 1:
		playback(names);
		break;
	case 2:
		break;
	}
}

/*void sorting() {
		bool swapped;
		int x; cout << "Enter 1 to sort by year  \nEnter 2 to sort by name\nEnter 3 to sort by rating  ";
		cin >> x;
		//sort by year //
		if (x == 1) {
			do {
				swapped = false;
				for (int i = 0; i < songs.size() - 1; i++) {
					if (song_data[i].year > song_data[i + 1].year) {
						swap(song_data[i].year, song_data[i + 1].year);
						swap(song_data[i].name, song_data[i + 1].name);
						swap(song_data[i].album, song_data[i + 1].album);
						swap(song_data[i].artist, song_data[i + 1].artist);
						swap(song_data[i].genre, song_data[i + 1].genre);
						swap(song_data[i].rating, song_data[i + 1].rating);
						swapped = true;
					}
				}
			} while (swapped);
		}
		// sort by name // 
		else if (x == 2) {
			do {
				//cout << "XX"; 
				swapped = false;
				for (int i = 0; i < songs.size() - 1; i++) {
					if (song_data[i].name > song_data[i + 1].name) {
						swap(song_data[i].year, song_data[i + 1].year);
						swap(song_data[i].name, song_data[i + 1].name);
						swap(song_data[i].album, song_data[i + 1].album);
						swap(song_data[i].artist, song_data[i + 1].artist);
						swap(song_data[i].genre, song_data[i + 1].genre);
						swap(song_data[i].rating, song_data[i + 1].rating);
						swapped = true;
				 	}
				}
			} while (swapped);


		}
		else if (x == 3) {
			do {
				//cout << "XX"; 
				swapped = false;
				for (int i = 0; i < songs.size() - 1; i++) {
					if (song_data[i].rating > song_data[i + 1].rating) {
						swap(song_data[i].year, song_data[i + 1].year);
						swap(song_data[i].name, song_data[i + 1].name);
						swap(song_data[i].album, song_data[i + 1].album);
						swap(song_data[i].artist, song_data[i + 1].artist);
						swap(song_data[i].genre, song_data[i + 1].genre);
						swap(song_data[i].rating, song_data[i + 1].rating);
						swapped = true;
					}
				}
			} while (swapped);


		}

	}*/

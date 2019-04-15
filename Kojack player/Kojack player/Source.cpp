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
#define Low_rating_activator 3
using namespace std;
bool quit = false;
bool menu = false; 
bool found;
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

int shuffled[max_numsongs] , counter=0;

bool shufflle = false;


vector<string> songs;
void get_all_files_names_within_folder(string folder);
void playMusic(const string& filename, int &play_num);
void playSound();
void list_display(vector<string> ToPlay, int what =1);
void playback(vector <string>names , int play_num);
void shuffle(vector<string>ToShuffle); 
void check_order(int &i, vector<string> playing);
void Read_MetaData();
void sorting();
void find(int choice);
int begin(bool first);
void decision(int x);
void View_all(int x);
void search();
void rate(int x , string name);
void Low_Rating(int x , string name);
void READ_RATING();
void search_display(string searched, int choice ,int year=0);



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
	return 0;
}


int begin(bool first)
{
	if (first) {
		cout << "Welcome in Kojack Player Thanks for using me " << endl;
		first = false; 
	}
	cout << "Press \n1 to view all songs in the system" << endl;
	cout << "2 to view all artists in the system\n3 to view all genres in the system" << endl;
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

void decision(int choice)
{
	switch (choice) {
	case 1: 
		list_display(songs , 0);
		break;
	case 2:
		View_all(1);
		break;
	case 3:
		View_all(2); 
		break;
	case 4 :
		View_all(3);
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

void View_all(int choice )
{
	set<string> ones;
	vector<string>one;
	int counter = 0;
	one.clear();
	// this switch puts the wanted data in a set and displays it
	switch (choice)
	{
	case 1 : 
		for (int i = 0; i < songs.size(); i++) {
			ones.insert(song_data[i].artist);
		}
		for (auto i : ones) {
			cout << counter + 1 << " ) " << i << endl;
			one.push_back(i);
			counter++;
		}
		cout << "Please enter the number of the artist you want to View : ";
		break;
	case 2:
		for (int i = 0; i < songs.size(); i++) {
			ones.insert(song_data[i].genre);
		}
		for (auto i : ones) {
			cout << counter + 1 << " ) " << i << endl;
			counter++;
			one.push_back(i);
		}
		cout << "Please enter the number of the genre you want to View : ";
		break;
	case 3:
		for (int i = 0; i < songs.size(); i++) {
			ones.insert(song_data[i].album);
		}
		for (auto i : ones) {
			cout <<counter+1 <<" ) " << i << endl;
			counter++;
			one.push_back(i);
		}	
		cout << "Please enter the number of the album you want to View : ";
		break;
	}
		
	int x; cin >> x;
	
	vector<string>plays;
	plays.clear();
	switch (choice)
	{
		case 1 :
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].artist == one[x - 1])
				{
					plays.push_back(songs[i]);
				}
			}
			break;
		case 2:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].genre == one[x - 1])
				{
					plays.push_back(songs[i]);
				}
			}
			break;
		case 3:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].album == one[x - 1])
				{
					plays.push_back(songs[i]);
				}
			}
			break;

	}
	list_display(plays, 1);
}

void list_display(vector<string> ToPlay, int what)
{
		system("cls");
		int x;
		for (int i = 0; i < ToPlay.size(); i++)
		{
			cout << i+1 << " : " << ToPlay[i] << endl;
		}
		cout << endl << endl;
		if (what == 0)
		{
			cout << "Press 1 to Play \nPress 2 to sort the list\nPress 3 to Play certain song (Not available while shuffling)\nPress 4 to Return to Kojack Menu" << endl;
			cin >> x;
			switch (x) {
			case 1:
				playback(ToPlay, 0);
				break;
			case 2:
				sorting();
				break;
			case 3:
				cout << "Enter song number :";
				cin >> x;
				playback(ToPlay, x - 1);
				break;
			case 4:
				break;
			}
		}
		else
		{
			cout << "Press 1 to Play \nPress 2 to Play certain song (Not available while shuffling)\nPress 3 to Return to Kojack Menu" << endl;
			cin >> x;
			switch (x) {
			case 1:
				playback(ToPlay, 0);
				break;
			case 2:
				cout << "Enter song number :";
				cin >> x;
				playback(ToPlay, x - 1);
				break;
			case 3:
				break;
			}
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
		if (song_data[i].rating <= Low_rating_activator && song_data[i].rating > 0)
		{
			int counter = 0;
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

void playMusic(const std::string& filename, int &play_num)
{
	// Load an ogg music file
	sf::Music music;
	if (!music.openFromFile(directory + filename))
		return;

	// Display music informations
	cout << filename << ":" << std::endl;
	cout << " " << music.getDuration().asSeconds() << " seconds" << std::endl;
	
	
	
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


void search()
{
	cout << flush << "Press \n1 To Search by name\n2 To Search by by Album\n3 To search by artist name\n4 To Search by genre\n5 To Search by year\n6 To Return to The Kojack Menu "<<endl;
	int n; cin >> n;
	switch (n)
	{
	case 1 :
		find(n);
		break;
	case 2 :
		find(n);
		break;
	case 3 :
		find(n);
		break;
	case 5:
		find(n);
		break;
	case 6 :
		return;
	default:
			cout << "not valid input" << endl;
			return search();
			break;

	}

}


void find(int choice )
{
	bool found = false;
	string s= "weg";
	switch (choice) {
	case 1:
		cout << "Enter Song Name : ";
		cin.ignore();
		getline(cin, s);
		if (s[0] >= 97 && s[0] <= 122)
			s[0] -= 32;
		search_display(s , choice);
		break;
	case 2:
		cout << "Enter Album : ";
		cin.ignore();
		getline(cin, s);

		if (s[0] >= 97 && s[0] <= 122)
			s[0] -= 32;
		search_display(s, choice);
		break;
	case 3:
		cout << "Enter Artist : ";
		cin.ignore();
		getline(cin, s);
		if (s[0] >= 97 && s[0] <= 122)
			s[0] -= 32;
		search_display(s, choice);
		break;
	case 4:
		int year; cin >> year;
		cout << "Enter Release Year : ";
		search_display( s , choice , year);
		break;
	}
		if (found == true)
		{

			cout << "Do You Wish To Play A Song? press '1' if ok else press 2 :";
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

void search_display(string searched, int choice, int year)
{
	vector<string> ToPlay;
	ToPlay.clear();
	switch (choice)
	{
		case 1:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].name.find(searched) < song_data[i].name.size())
				{
					ToPlay.push_back(song_data[i].name);
					found = true;
				}
			}
			break;
		case 2:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].album.find(searched) < song_data[i].album.size())
				{
					ToPlay.push_back(song_data[i].name);
					found = true;
				}
			}
			break;
		case 3:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].artist.find(searched) != -1)
				{
					ToPlay.push_back(song_data[i].name);
					found = true;
				}
			}
			break;
		case 4:
			for (int i = 0; i < songs.size(); i++)
			{
				if (song_data[i].year == year)
				{
					ToPlay.push_back(song_data[i].name);
					found = true;
				}
			}
			break;
	}
	if (found)
	{
		list_display(ToPlay);
	}
	else {
		cout << "Not Found" << endl;
	}
}

// below here is done
void sorting()
{
	vector<string> names;
	names.clear();
	cout << "Enter\n1 to sort high to low\n2 to sort low to high :" ;
	int x, counter = 0; cin >> x;
	system("cls"); 
	if (x == 1)
	{
		for (int i = 10; i >= 0; i--) {
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
		for (int i = 0; i <= 10; i++) {
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
		playback(names,0);
		break;
	case 2:
		break;
	}
}

void rate(int x, string name)
{
	int rating;
	cout << "Enter Rating (1-10):";
	while (true)
	{
		cin >> rating;
		if (rating > 10 || rating < 0)
		{
			cout << "Invalid rating \nEnter Rating :";
		}
		else
		{
			if (rating <= Low_rating_activator)
			{
				Low_Rating(x , name); //playsound !display
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

void Low_Rating(int x , string name)
{
	playSound();
	for (int i = 0; i < songs.size(); i++)
	{
		if (name == song_data[i].name)
		{
			song_data[i].display = false;
		}
	}
}

void playSound()
{
	// Load a sound buffer from a wav file
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Tda5ol.wav"))
		return;

	sf::Sound sound(buffer);
	sound.play();
// Loop while the sound is playing
	while (sound.getStatus() == sf::Sound::Playing)
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));
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

void check_order(int &i ,vector <string> playing)
{
	// the final i in both cases will be incrmented in the for loop in the calling function

	// to play the first song after the last song
	if (i == playing.size() - 1)
	{
		i = -1;
	}
	// if you play the previous song while playing the first song in the list the i would be -2 
	else if (i == -2)
	{
		i = playing.size() - 2;
	}
}

void playback(vector<string>names , int play_num)
{
	system("cls");
	if (!shufflle) {
	for (int i = play_num ; i < names.size(); i++)
	{
		playMusic(names[i], i);
		check_order(i, names);
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
			playMusic(names[shuffled[i]], i);
			check_order(i , names);
			system("cls");
			if (menu)
			{
				menu = false;
				return;
			}
		}
	}
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

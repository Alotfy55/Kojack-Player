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
#define directory "C:\\Users\\Omadex\\Desktop\\Kojack player\\resources/"
#define max_numsongs 10000
using namespace std;

struct song
{
	string name;
	string genre;
	string album;
	string artist;
	int year;
}song_data[10000];

bool found = false;
vector<string> songs;
void get_all_files_names_within_folder(string folder);
void playMusic(const string& filename, int &play_num);
void list_display();
void playback();
void shuffle();
void check_order(int &i);
void read();
int ziad_pressed();
void find_by_name();
void find_by_genre();
void find_by_album();
void find_by_artist();
void find_by_year();

int main()
{
	char key;
	int ascii;
	// Welcome to main 
	get_all_files_names_within_folder(directory);
	read();
	cout << "to play in shuffle press 's','f' to find a song and 'p' to play the default playlist ";
	//cout << "Press 'f' to find a song";
	ziad_pressed();
	//char play; cin >> play;
	if (ziad_pressed() == 70||ziad_pressed()==102)
	{
		cout << "To Find by name press '1', genre press '2',album press '3', artist press '4', year press '5'";
		//int c; cin >> c;
		if (ziad_pressed() == 49)
			find_by_name();
		else if (ziad_pressed() == 50)
			find_by_genre();
		else if (ziad_pressed() == 51)
			find_by_album();
		else if (ziad_pressed() == 52)
			find_by_artist();
		else if (ziad_pressed() == 53)
			find_by_year();
	}

	else if (ziad_pressed()==83||ziad_pressed()==115)
		shuffle();
	else if (ziad_pressed()==80||ziad_pressed()==112)
		playback();
	
	if (ziad_pressed() == 27)
	{
		return 0;
	}
	system("pause");
	return 0;
}
void shuffle()
{
	/* this function shuffles the indecies and put them in array named shuffled
		then uses the array shuffled as an index to play music from the vector songs */


	array <int, max_numsongs> shuffled_order = {};
	// intializing the array with values from 1 to the number of songs in the folder
	for (int i = 1; i <= songs.size(); i++)
	{
		shuffled_order[i] = i;
	}
	// generating 
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(shuffled_order.begin(), shuffled_order.end(), default_random_engine(seed));

	int shuffled[max_numsongs], counter = 0;
	for (int i = 0; i < max_numsongs; i++)
	{
		if (shuffled_order[i] != 0)
		{
			shuffled[counter] = shuffled_order[i] - 1;
			counter++;
		}
	}
	for (int i = 1; i <= songs.size(); i++)
	{
		cout << i << ": " << songs[shuffled[i - 1]] << endl;

	}
	cout << endl;
	for (int i = 0; i < songs.size(); i++)
	{
		playMusic(songs[shuffled[i]], i);
		check_order(i);
	}
}
void list_display()
{
	cout << "Please enter the number of the song you want to play from the following list : " << endl;
	for (int i = 1; i <= songs.size(); i++)
	{
		cout << i << " : " << songs[i - 1] << endl;
	}
	cout << endl << endl;
}
void playback()
{
	list_display();
	int n; cin >> n;
	for (int i = n - 1; i < songs.size(); i++)
	{
		playMusic(songs[i], i);
		check_order(i);
		
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
	while (music.getStatus() == sf::Music::Playing && music.getPlayingOffset().asSeconds() < music.getDuration().asSeconds())
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));

		// Display the playing position
		std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        ";
		std::cout << std::flush;
		ziad_pressed();
		if(ziad_pressed()==112)
		{
			music.pause();
		}

	}
	std::cout << std::endl << std::endl;
}
void read()
{
	fstream fs;
	fs.open("data.txt");
	for (int i = 0; i < songs.size(); i++)
	{
		getline(fs, song_data[i].artist);
		getline(fs, song_data[i].album);
		fs >> song_data[i].year;
		cout << song_data[i].artist << endl;
	}

}
void find_by_name()
{
	cout << "Enter Song Name : ";
	string s; getline(cin, s);
	for (int i = 0; i < songs.size(); i++)
	{
		found = false;
		if (s.find(song_data[i].name) != -1)
		{
			cout << i << song_data[i].name;
			found = true;
		}
	}
	if (found == true)
	{

		cout << "Do You Wish To Play A Song? press '1' if ok else press 2";
		//char command; cin >> command;
		if (ziad_pressed() == 49)
		{
			cout << "Enter Song Number : ";
			int sN; cin >> sN;
			playMusic(song_data[sN].name, sN);
		}
	}
	else
		cout << "Not Found!";
}
void find_by_genre()
{
	cout << "Enter Genre : ";
	string s; getline(cin, s);
	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (s.find(song_data[i].genre) != -1)
		{
			cout << i << song_data[i].name;
			found = true;
		}
		else
			cout << "Not Found!";
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
}
void find_by_album()
{
	cout << "Enter Album : ";
	string s; getline(cin, s);
	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (s.find(song_data[i].album) != -1)
		{
			cout << i << song_data[i].name;
			found = true;
		}
		else
			cout << "Not Found!";
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
}
void find_by_artist()
{
	cout << "Enter Artist : ";
	string s; getline(cin, s);
	found = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (s.find(song_data[i].artist) != -1)
		{
			cout << i << song_data[i].name;
			found = true;
		}
		else
			cout << "Not Found!";
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
			cout << i << song_data[i].name;
			found = true;
		}
		else
			cout << "Not Found!";
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
}
int ziad_pressed()
{
	char key;
	int ascii;
	key = getch();
	ascii = key;

	return ascii;

}
//if (cin >> x)
//{
//	if (x == 'p' &&  music.getStatus() == sf::Music::Playing)
//		music.pause();
//	else if (x == 'p')
//		music.play();
//	else if (x == 'n')
//	{
//		//next
//		return;
//	}
//	else if (x == 's' && music.getStatus() == sf::Music::Playing)
//	{
//		music.stop();
//	}
//	else if (x == 'b')
//	{
//		//b as in backwards 
//		play_num-=2;
//		return;
//	}
//	
//}

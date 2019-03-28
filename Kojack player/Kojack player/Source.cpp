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
#define directory "C:\\Users\\Owner\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\resources"
using namespace std;

vector<string> songs;
void get_all_files_names_within_folder(string folder);
void playMusic(const string& filename, int &play_num);
void list_display();
void playback();
int main()
{
	// Welcome to main 
	get_all_files_names_within_folder(directory);
	list_display();
	playback();
	system("pause");
	return 0;
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
	int n; cin >> n;
	for (int i = n - 1; i < songs.size(); i++)
	{
		playMusic(songs[i], i);
		if (i == songs.size() - 1)
		{
			i = -1;
		}
		else if (i == -2)
		{
			i = songs.size() - 2; 
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
		do 
		{
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
			{
				
				songs.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}
void playMusic(const string& filename, int &play_num)
{
	//Plays the song
	// Load an wave music file
	sf::Music music;
	if (!music.openFromFile("resources/" + filename))
		return;

	// Display music informations
	cout << filename << ":" << endl;
	cout << " " << music.getDuration().asSeconds() << " seconds" << endl;
	
	char x;
	// Play it
	music.play();

	// Loop while the music is playing

	cout << "Press p to pause , press it again to play \t Press n to play next song  \t Press s to stop music \t Press b to go back \t"<<endl;
	while (music.getStatus() == sf::Music::Playing || music.getPlayingOffset().asSeconds() < music.getDuration().asSeconds())
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));
		// Display the playing position
		cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec       ";
		cout << flush;
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
		}
	}
	cout << endl << endl;
}
//struct song
//{
//	string name;
//	string genre;
//	string album ;
//	string artist;
//	int year;
//}song_data[1000];

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct song
{
	string name;
	string genre; 
	int id;
	string artist; 
};
//accessing the data of each song with a unique id , another idea is fuck ids we use the songs name to call for its data
int song_entrey();
map <int, song> sang;
vector <string> songs;
void playMusic(const string& filename)
{
	cout << filename << endl;
	// Load an ogg music file
	sf::Music music;
	if (!music.openFromFile("resources/" + filename + ".wav"))
		return;

	// Display music informations
	cout << filename << ":" << endl;
	cout << " " << music.getDuration().asSeconds() << " seconds" << endl;
	cout << " " << music.getSampleRate() << " samples / sec" << endl;
	cout << " " << music.getChannelCount() << " channels" << endl;

	// Play it
	music.play();

	// Loop while the music is playing
	while (music.getStatus() == sf::Music::Playing)
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));

		// Display the playing position
		cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " seckjjk        ";
		cout << flush;
	}
	cout << endl << endl;
}
int main () 
{
	int nums;
	nums = song_entrey();
	
	for (int i = 0; i <= nums; i++)
	{
		playMusic(songs[i]);
	}
	system("pause");
	return 0; 
}
int song_entrey()
{
	int num_songs;
	cout << "How many songs are you adding ?? :";
	cin >> num_songs;
	string name ; 
	for (int i = 0; i <= num_songs; i++)
	{
		cout << endl<< "Enter song name :"; 
		getline(cin,name);
		songs.push_back(name);
	}
	return num_songs;
}

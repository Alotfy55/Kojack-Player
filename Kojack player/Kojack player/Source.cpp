#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector <string> songs;
void playMusic(const std::string& filename)
{
	std::cout << filename <<std::endl;
	// Load an ogg music file
	sf::Music music;
	if (!music.openFromFile("resources/" + filename + ".wav"))
		return;

	// Display music informations
	std::cout << filename << ":" << std::endl;
	std::cout << " " << music.getDuration().asSeconds() << " seconds" << std::endl;
	std::cout << " " << music.getSampleRate() << " samples / sec" << std::endl;
	std::cout << " " << music.getChannelCount() << " channels" << std::endl;

	// Play it
	music.play();

	// Loop while the music is playing
	while (music.getStatus() == sf::Music::Playing)
	{
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));

		// Display the playing position
		std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        ";
		std::cout << std::flush;
	}
	std::cout << std::endl << std::endl;
}
int song_entrey();
int main () 
{
	
	int nums = song_entrey();
	for (int i = 1; i <= nums; i++)
	{
		playMusic(songs[i]);
	}
	system("pause");
	return 0; 
}
int song_entrey()
{
	int num_songs;
	cout << "How many songs are you adding ?? :" << endl;
	cin >> num_songs;
	for (int i = 1; i <= num_songs; i++)
	{
		cout << endl<< "Enter song name : "; 
		string name; 
		getline(cin,name);
		songs.push_back(name);
	}
	return num_songs;
}
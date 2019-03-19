#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
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
int main () 
{
	std::string x;
	getline(std::cin, x);
	playMusic(x);
	return main (); 
}
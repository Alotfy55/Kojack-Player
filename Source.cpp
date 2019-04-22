#pragma warning(disable : 4996) //Disables error (4996) bec it is just vs freaking on us  
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
#include <random>       
#include <chrono> 
#include <conio.h>
#define directory "C:\\Users\\lenovo\\Documents\\GitHub\\Kojack-Player\\Kojack player\\Kojack player\\resources/"
#define max_numsongs 10000
#define Low_rating_activator 3
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
bool quit = false;
bool menu = false;
bool found;

int shuffled[max_numsongs], counter = 0;

bool shufflle = false;
vector<string> songs;



void wpage(sf::RenderWindow& window, sf::Event& event, string& mod, sf::Vector2f& mouse_position);
void datapage(sf::RenderWindow& window, sf::Event& event, string& mod, sf::Vector2f& mouse_position);
bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position);
void song_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod);
void get_all_files_names_within_folder(string folder);
void Read_MetaData();
void READ_RATING();
void album_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod);
void artist_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod);
void genre_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod);
void list_display(vector<string> ToPlay, int what = 1);


void playMusic(const std::string& filename, int &play_num, sf::Vector2f& mouse_position, sf::Sprite& play_sprite, sf::Event& event, sf::Window& window, sf::Sprite& foward_sprite
	, sf::Sprite& backward_sprite, sf::Sprite& shuffle_sprite);

int main() {
	get_all_files_names_within_folder(directory);


	sf::Vector2f mouse_position;
	string mod = "welcome";

	sf::RenderWindow starting_window(sf::VideoMode(600, 300), "Kojack Player", sf::Style::Default);
	while (starting_window.isOpen())
	{
		sf::Event starting;
		while (starting_window.pollEvent(starting))
		{
			if (starting.type == sf::Event::Closed) {
				starting_window.close();
			}
			mouse_position.x = sf::Mouse::getPosition(starting_window).x;
			mouse_position.y = sf::Mouse::getPosition(starting_window).y;

			if (mod == "welcome")
			{
				starting_window.clear();
				wpage(starting_window, starting, mod, mouse_position);
				

			}
			if (mod == "login")
			{
				starting_window.clear();
				datapage(starting_window, starting, mod, mouse_position);

			}
			if (mod == "sign up")
			{
				starting_window.clear();
				datapage(starting_window, starting, mod, mouse_position);

			}

			starting_window.display();
			starting_window.clear();

		}
	}



	Read_MetaData();
	READ_RATING();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Kojack Player", sf::Style::Default);
	mod = "song";
	
	cout << songs.size() << endl;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			mouse_position.x = sf::Mouse::getPosition(window).x;
			mouse_position.y = sf::Mouse::getPosition(window).y;
			//cout << mouse_position.x << "\t" << mouse_position.y << endl;
			if (mod == "song") {
				window.clear();
				song_tab(window, mouse_position , event , mod);
			}
			if (mod == "album") {
				window.clear();
				album_tab(window, mouse_position, event, mod);
			}
			if (mod == "artist") {
				window.clear();
				artist_tab(window, mouse_position, event, mod);

			}
			if (mod == "genre") {
				window.clear();
				genre_tab(window, mouse_position, event, mod);
			}
			window.display();
		}


		//window.display();
	}






	return 0;
}




bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position) {
	if (sprite.contains(mouse_position)) {
		list_display(songs, 0);

		return true;
	}
	return false;
}

void song_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod) {
	window.clear();

	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape play_button;
	sf::Texture play_pic;
	sf::RectangleShape backward_button;
	sf::Texture backward_pic;
	sf::Sprite backward_sprite;
	sf::Sprite play_sprite;
	sf::RectangleShape forward_button;
	sf::Texture forward_pic;
	sf::Sprite forward_sprite;
	sf::RectangleShape shuffle_button;
	sf::Texture shuffle_pic;
	sf::Sprite shuffle_sprite;
	sf::RectangleShape songs_list;
	sf::RectangleShape artist_list;
	sf::RectangleShape album_list;
	sf::RectangleShape genre_list;
	sf::Texture album_pic;
	sf::Sprite album_sprite;
	sf::Texture genre_pic;
	sf::Sprite genre_sprite;
	sf::Texture song_pic;
	sf::Sprite song_sprite;
	sf::Texture artist_pic;
	sf::Sprite artist_sprite;
	sf::RectangleShape search_box;
	sf::Texture search_pic;
	sf::Sprite search_sprite;
	sf::Text seacr_text;
	sf::RectangleShape rating_bar;
	RectangleShape music_box[20];
	Text name_music[20];
	Font use_font;
	use_font.loadFromFile("Roboto-ThinItalic.ttf");

	float x = 55;
	for (int i = 0; i < 14; ++i) {

		music_box[i].setSize(Vector2f(200, 30));
		music_box[i].setPosition(3, x);
		music_box[i].setFillColor(Color::Transparent);
		name_music[i].setFont(use_font);
		name_music[i].setStyle(Text::Bold);
		name_music[i].setString(songs[i]);
		name_music[i].setColor(Color::Red);
		name_music[i].setPosition(5, x);
		name_music[i].setCharacterSize(24);
		x += 33;
		

	}







	rating_bar.setSize(sf::Vector2f(200, 40));
	rating_bar.setPosition(580, 535);
	rating_bar.setFillColor(sf::Color::Green);



	search_box.setSize(sf::Vector2f(200, 40));
	search_box.setPosition(520, 75);
	search_pic.loadFromFile("search bar.png");
	search_box.setTexture(&search_pic);
	search_sprite.setTexture(search_pic);
	search_sprite.setPosition(520, 75);




	play_button.setSize(sf::Vector2f(75, 75));
	play_button.setOrigin(25, 25);
	play_button.setPosition(400, 540);
	play_pic.loadFromFile("pause-play.png");
	play_button.setTexture(&play_pic);
	play_sprite.setTexture(play_pic);
	play_sprite.setOrigin(25, 25);
	play_sprite.setPosition(400, 550);



	backward_button.setSize(sf::Vector2f(75, 75));
	backward_button.setOrigin(25, 25);
	backward_button.setPosition(300, 540);
	backward_pic.loadFromFile("previous.png");
	backward_button.setTexture(&backward_pic);
	backward_sprite.setTexture(backward_pic);
	backward_sprite.setOrigin(25, 25);
	backward_sprite.setPosition(300, 550);




	forward_button.setSize(sf::Vector2f(75, 75));
	forward_button.setOrigin(25, 25);
	forward_button.setPosition(500, 540);
	forward_pic.loadFromFile("next.png");
	forward_button.setTexture(&forward_pic);
	forward_sprite.setTexture(forward_pic);
	forward_sprite.setOrigin(25, 25);
	forward_sprite.setPosition(500, 550);



	shuffle_button.setSize(sf::Vector2f(75, 75));
	shuffle_button.setOrigin(37.5, 37.5);
	shuffle_button.setPosition(150, 550);
	shuffle_pic.loadFromFile("shuffle.png");
	shuffle_button.setTexture(&shuffle_pic);
	shuffle_sprite.setTexture(shuffle_pic);
	shuffle_sprite.setPosition(150, 550);
	shuffle_sprite.setOrigin(12.5, 12.5);






	songs_list.setSize(sf::Vector2f(200, 50));
	songs_list.setPosition(0, 0);
	song_pic.loadFromFile("songs  pressed.png");
	songs_list.setTexture(&song_pic);
	song_sprite.setTexture(song_pic);
	song_sprite.setPosition(0, 0);



	artist_list.setSize(sf::Vector2f(200, 50));

	artist_list.setPosition(200, 0);
	artist_pic.loadFromFile("artists unpressed.png");
	artist_list.setTexture(&artist_pic);
	artist_sprite.setTexture(artist_pic);
	artist_sprite.setPosition(200, 0);





	album_list.setSize(sf::Vector2f(200, 50));
	album_list.setPosition(400, 0);
	album_pic.loadFromFile("albums unpressed.png");
	album_list.setTexture(&album_pic);
	album_sprite.setTexture(album_pic);
	album_sprite.setPosition(400, 0);



	genre_list.setSize(sf::Vector2f(200, 50));

	genre_list.setPosition(600, 0);
	genre_pic.loadFromFile("genres unpressed.png");
	genre_list.setTexture(&genre_pic);
	genre_sprite.setTexture(genre_pic);
	genre_sprite.setPosition(600, 0);





	back_pic.setSize(sf::Vector2f(800.0f, 600.0f));
	background_texture.loadFromFile("wallpaper dark final final.png");
	if (!background_texture.loadFromFile("wallpaper dark final final.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(shuffle_button);
	window.draw(genre_list);
	window.draw(album_list);
	window.draw(songs_list);
	window.draw(artist_list);
	window.draw(rating_bar);
	window.draw(backward_button);
	window.draw(forward_button);
	window.draw(play_button);
	window.draw(search_box);
	for (int i = 0; i < 14 ; i++) {
		window.draw(music_box[i]);
		window.draw(name_music[i]);
	}





	if (focus(album_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "album";

		}
	}
	if (focus(genre_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "genre";

		}
	}
	if (focus(artist_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "artist";

		}
	}


	/////// search button pressing
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}


	//////////////string to search for 
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}



	////////play button pressing
	if (focus(play_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			
		}
	}


	/////// enabling shuffle 
	if (focus(shuffle_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}

	///////// backward button pressing
	if (focus(backward_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}

	///////// forward button pressing 
	if (focus(forward_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}

	for (int i = 0; i < 13 ; i++) {

		if (focus(music_box[i].getGlobalBounds(), mouse_position))
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
			{

				playMusic(songs[i], i , mouse_position , play_sprite , event , window  , forward_sprite , backward_sprite , shuffle_sprite);
				
			}
		}
	}
}

void list_display(vector<string> songs, int what)
{
	system("cls");
	
	for (int i = 0; i < songs.size(); i++)
	{

		cout << i + 1 << " : " << songs[i] << endl;
	}

	//cout << endl << endl << songs.size();




}



void playMusic(const std::string& filename, int &play_num , sf::Vector2f& mouse_position , sf::Sprite& play_sprite , sf::Event& event , sf::Window& window , sf::Sprite& foward_sprite
 , sf::Sprite& backward_sprite , sf::Sprite& shuffle_sprite)
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

	while (music.getStatus() == sf::Music::Playing || music.getPlayingOffset().asSeconds() < music.getDuration().asSeconds())
	{
		mouse_position.x = sf::Mouse::getPosition(window).x;
		mouse_position.y = sf::Mouse::getPosition(window).y;
		cout << mouse_position.x << "\t" << mouse_position.y << endl ;
		// Leave some CPU time for other processes
		sf::sleep(sf::milliseconds(100));
		if (music.getPlayingOffset().asSeconds() == music.getDuration().asSeconds()) {
			break;
		}
		// Display the playing position
		//std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        ";
		//std::cout << std::flush;
		//std::cout << std::endl << std::endl;
		if (focus(play_sprite.getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				if (music.getStatus() == sf::Music::Playing)
					music.pause();
				else if (music.getStatus() == sf::Music::Paused) {
					music.play();
				}
			}
		}
		if (focus(backward_sprite.getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				
				return;
				
			}
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


void READ_RATING()
{
	fstream Rating_file;
	Rating_file.open("Rating.txt");
	for (int i = 0; i < songs.size(); i++)
	{
		Rating_file >> song_data[i].rating;
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





void album_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod) {
	window.clear();

	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape play_button;
	sf::Texture play_pic;
	sf::RectangleShape backward_button;
	sf::Texture backward_pic;
	sf::Sprite backward_sprite;
	sf::Sprite play_sprite;
	sf::RectangleShape forward_button;
	sf::Texture forward_pic;
	sf::Sprite forward_sprite;
	sf::RectangleShape shuffle_button;
	sf::Texture shuffle_pic;
	sf::Sprite shuffle_sprite;
	sf::RectangleShape songs_list;
	sf::RectangleShape artist_list;
	sf::RectangleShape album_list;
	sf::RectangleShape genre_list;
	sf::Texture album_pic;
	sf::Sprite album_sprite;
	sf::Texture genre_pic;
	sf::Sprite genre_sprite;
	sf::Texture song_pic;
	sf::Sprite song_sprite;
	sf::Texture artist_pic;
	sf::Sprite artist_sprite;
	sf::RectangleShape search_box;
	sf::Texture search_pic;
	sf::Sprite search_sprite;
	sf::Text seacr_text;
	RectangleShape album[20];
	Text name_album[20];
	Font use_font;
	use_font.loadFromFile("Roboto-ThinItalic.ttf");



	float x = 55;
	for (int i = 0; i <= 13; ++i) {
		album[i].setSize(Vector2f(200, 30));
		album[i].setPosition(0, x);
		album[i].setFillColor(Color::Transparent); name_album[i].setFont(use_font);
		name_album[i].setStyle(Text::Bold);
		name_album[i].setString("amr diab");
		name_album[i].setColor(Color::Red);
		name_album[i].setPosition(0, x);
		name_album[i].setCharacterSize(24);
		x += 33;

	}





	search_box.setSize(sf::Vector2f(200, 40));
	search_box.setPosition(520, 75);
	search_pic.loadFromFile("search bar.png");
	search_box.setTexture(&search_pic);
	search_sprite.setTexture(search_pic);
	search_sprite.setPosition(520, 75);

	play_button.setSize(sf::Vector2f(75, 75));
	play_button.setOrigin(25, 25);
	play_button.setPosition(400, 540);
	play_pic.loadFromFile("pause-play.png");
	play_button.setTexture(&play_pic);
	play_sprite.setTexture(play_pic);
	play_sprite.setOrigin(25, 25);
	play_sprite.setPosition(400, 550);



	backward_button.setSize(sf::Vector2f(75, 75));
	backward_button.setOrigin(25, 25);
	backward_button.setPosition(300, 540);
	backward_pic.loadFromFile("previous.png");
	backward_button.setTexture(&backward_pic);
	backward_sprite.setTexture(backward_pic);
	backward_sprite.setOrigin(25, 25);
	backward_sprite.setPosition(300, 550);




	forward_button.setSize(sf::Vector2f(75, 75));
	forward_button.setOrigin(25, 25);
	forward_button.setPosition(500, 540);
	forward_pic.loadFromFile("next.png");
	forward_button.setTexture(&forward_pic);
	forward_sprite.setTexture(forward_pic);
	forward_sprite.setOrigin(25, 25);
	forward_sprite.setPosition(500, 550);



	shuffle_button.setSize(sf::Vector2f(75, 75));
	shuffle_button.setOrigin(37.5, 37.5);
	shuffle_button.setPosition(150, 550);
	shuffle_pic.loadFromFile("shuffle.png");
	shuffle_button.setTexture(&shuffle_pic);
	shuffle_sprite.setTexture(shuffle_pic);
	shuffle_sprite.setPosition(150, 550);
	shuffle_sprite.setOrigin(12.5, 12.5);






	songs_list.setSize(sf::Vector2f(200, 50));

	songs_list.setPosition(0, 0);
	song_pic.loadFromFile("songs 200  unpressed.png");
	songs_list.setTexture(&song_pic);
	song_sprite.setTexture(song_pic);
	song_sprite.setPosition(0, 0);



	artist_list.setSize(sf::Vector2f(200, 50));

	artist_list.setPosition(200, 0);
	artist_pic.loadFromFile("artists unpressed.png");
	artist_list.setTexture(&artist_pic);
	artist_sprite.setTexture(artist_pic);
	artist_sprite.setPosition(200, 0);





	album_list.setSize(sf::Vector2f(200, 50));
	album_list.setPosition(400, 0);
	album_pic.loadFromFile("albums pressed.png");
	album_list.setTexture(&album_pic);
	album_sprite.setTexture(album_pic);
	album_sprite.setPosition(400, 0);



	genre_list.setSize(sf::Vector2f(200, 50));

	genre_list.setPosition(600, 0);
	genre_pic.loadFromFile("genres unpressed.png");
	genre_list.setTexture(&genre_pic);
	genre_sprite.setTexture(genre_pic);
	genre_sprite.setPosition(600, 0);





	back_pic.setSize(sf::Vector2f(800.0f, 600.0f));
	background_texture.loadFromFile("wallpaper dark final final.png");
	if (!background_texture.loadFromFile("wallpaper dark final final.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(shuffle_button);
	window.draw(genre_list);
	window.draw(album_list);
	window.draw(search_box);
	window.draw(songs_list);
	window.draw(artist_list);
	window.draw(backward_button);
	window.draw(forward_button);
	window.draw(play_button);
	for (int i = 0; i <= 13; i++) {
		window.draw(album[i]);
		window.draw(name_album[i]);
	}




	if (focus(song_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "song";

		}
	}
	if (focus(genre_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "genre";

		}
	}
	if (focus(artist_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "artist";

		}
	}

	/////// search button pressing
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}


	//////////////string to search for 
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}




}


void artist_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod) {
	window.clear();

	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape play_button;
	sf::Texture play_pic;
	sf::RectangleShape backward_button;
	sf::Texture backward_pic;
	sf::Sprite backward_sprite;
	sf::Sprite play_sprite;
	sf::RectangleShape forward_button;
	sf::Texture forward_pic;
	sf::Sprite forward_sprite;
	sf::RectangleShape shuffle_button;
	sf::Texture shuffle_pic;
	sf::Sprite shuffle_sprite;
	sf::RectangleShape songs_list;
	sf::RectangleShape artist_list;
	sf::RectangleShape album_list;
	sf::RectangleShape genre_list;
	sf::Texture album_pic;
	sf::Sprite album_sprite;
	sf::Texture genre_pic;
	sf::Sprite genre_sprite;
	sf::Texture song_pic;
	sf::Sprite song_sprite;
	sf::Texture artist_pic;
	sf::Sprite artist_sprite;
	sf::RectangleShape search_box;
	sf::Texture search_pic;
	sf::Sprite search_sprite;
	sf::Text seacr_text;
	RectangleShape artist[20];
	Text name_artist[20];
	Font use_font;
	use_font.loadFromFile("Roboto-ThinItalic.ttf");



	float x = 55;
	for (int i = 0; i <= 13; ++i) {
		artist[i].setSize(Vector2f(200, 30));
		artist[i].setPosition(0, x);
		artist[i].setFillColor(Color::Transparent);
		name_artist[i].setFont(use_font);
		name_artist[i].setStyle(Text::Bold);
		name_artist[i].setString("amr diab");
		name_artist[i].setColor(Color::Red);
		name_artist[i].setPosition(0, x);
		name_artist[i].setCharacterSize(24);
		x += 33;

	}





	search_box.setSize(sf::Vector2f(200, 40));
	search_box.setPosition(520, 75);
	search_pic.loadFromFile("search bar.png");
	search_box.setTexture(&search_pic);
	search_sprite.setTexture(search_pic);
	search_sprite.setPosition(520, 75);

	play_button.setSize(sf::Vector2f(75, 75));
	play_button.setOrigin(25, 25);
	play_button.setPosition(400, 540);
	play_pic.loadFromFile("pause-play.png");
	play_button.setTexture(&play_pic);
	play_sprite.setTexture(play_pic);
	play_sprite.setOrigin(25, 25);
	play_sprite.setPosition(400, 550);



	backward_button.setSize(sf::Vector2f(75, 75));
	backward_button.setOrigin(25, 25);
	backward_button.setPosition(300, 540);
	backward_pic.loadFromFile("previous.png");
	backward_button.setTexture(&backward_pic);
	backward_sprite.setTexture(backward_pic);
	backward_sprite.setOrigin(25, 25);
	backward_sprite.setPosition(300, 550);




	forward_button.setSize(sf::Vector2f(75, 75));
	forward_button.setOrigin(25, 25);
	forward_button.setPosition(500, 540);
	forward_pic.loadFromFile("next.png");
	forward_button.setTexture(&forward_pic);
	forward_sprite.setTexture(forward_pic);
	forward_sprite.setOrigin(25, 25);
	forward_sprite.setPosition(500, 550);



	shuffle_button.setSize(sf::Vector2f(75, 75));
	shuffle_button.setOrigin(37.5, 37.5);
	shuffle_button.setPosition(150, 550);
	shuffle_pic.loadFromFile("shuffle.png");
	shuffle_button.setTexture(&shuffle_pic);
	shuffle_sprite.setTexture(shuffle_pic);
	shuffle_sprite.setPosition(150, 550);
	shuffle_sprite.setOrigin(12.5, 12.5);






	songs_list.setSize(sf::Vector2f(200, 50));

	songs_list.setPosition(0, 0);
	song_pic.loadFromFile("songs 200  unpressed.png");
	songs_list.setTexture(&song_pic);
	song_sprite.setTexture(song_pic);
	song_sprite.setPosition(0, 0);



	artist_list.setSize(sf::Vector2f(200, 50));

	artist_list.setPosition(200, 0);
	artist_pic.loadFromFile("artists pressed.png");
	artist_list.setTexture(&artist_pic);
	artist_sprite.setTexture(artist_pic);
	artist_sprite.setPosition(200, 0);





	album_list.setSize(sf::Vector2f(200, 50));
	album_list.setPosition(400, 0);
	album_pic.loadFromFile("albums unpressed.png");
	album_list.setTexture(&album_pic);
	album_sprite.setTexture(album_pic);
	album_sprite.setPosition(400, 0);



	genre_list.setSize(sf::Vector2f(200, 50));

	genre_list.setPosition(600, 0);
	genre_pic.loadFromFile("genres unpressed.png");
	genre_list.setTexture(&genre_pic);
	genre_sprite.setTexture(genre_pic);
	genre_sprite.setPosition(600, 0);





	back_pic.setSize(sf::Vector2f(800.0f, 600.0f));
	background_texture.loadFromFile("wallpaper dark final final.png");
	if (!background_texture.loadFromFile("wallpaper dark final final.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(shuffle_button);
	window.draw(genre_list);
	window.draw(album_list);
	window.draw(search_box);
	window.draw(songs_list);
	window.draw(artist_list);
	window.draw(backward_button);
	window.draw(forward_button);
	window.draw(play_button);
	for (int i = 0; i <= 13; i++) {
		window.draw(artist[i]);
		window.draw(name_artist[i]);
	}





	if (focus(album_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "album";

		}
	}
	if (focus(genre_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "genre";

		}
	}
	if (focus(song_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "song";

		}
	}



	/////// search button pressing
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}


	//////////////string to search for 
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}
}



void genre_tab(sf::RenderWindow& window, sf::Vector2f& mouse_position, sf::Event& event, string& mod) {
	window.clear();

	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape play_button;
	sf::Texture play_pic;
	sf::RectangleShape backward_button;
	sf::Texture backward_pic;
	sf::Sprite backward_sprite;
	sf::Sprite play_sprite;
	sf::RectangleShape forward_button;
	sf::Texture forward_pic;
	sf::Sprite forward_sprite;
	sf::RectangleShape shuffle_button;
	sf::Texture shuffle_pic;
	sf::Sprite shuffle_sprite;
	sf::RectangleShape songs_list;
	sf::RectangleShape artist_list;
	sf::RectangleShape album_list;
	sf::RectangleShape genre_list;
	sf::Texture album_pic;
	sf::Sprite album_sprite;
	sf::Texture genre_pic;
	sf::Sprite genre_sprite;
	sf::Texture song_pic;
	sf::Sprite song_sprite;
	sf::Texture artist_pic;
	sf::Sprite artist_sprite;
	sf::RectangleShape search_box;
	sf::Texture search_pic;
	sf::Sprite search_sprite;
	sf::Text seacr_text;
	RectangleShape genre[20];
	Text name_genre[20];
	Font use_font;
	use_font.loadFromFile("Roboto-ThinItalic.ttf");



	float x = 55;
	for (int i = 0; i <= 13; ++i) {
		genre[i].setSize(Vector2f(200, 30));
		genre[i].setPosition(0, x);
		genre[i].setFillColor(Color::Transparent);
		name_genre[i].setFont(use_font);
		name_genre[i].setStyle(Text::Bold);
		name_genre[i].setString("amr diab");
		name_genre[i].setColor(Color::Red);
		name_genre[i].setPosition(0, x);
		name_genre[i].setCharacterSize(24);

		x += 33;

	}


	search_box.setSize(sf::Vector2f(200, 40));
	search_box.setPosition(520, 75);
	search_pic.loadFromFile("search bar.png");
	search_box.setTexture(&search_pic);
	search_sprite.setTexture(search_pic);
	search_sprite.setPosition(520, 75);

	play_button.setSize(sf::Vector2f(75, 75));
	play_button.setOrigin(25, 25);
	play_button.setPosition(400, 540);
	play_pic.loadFromFile("pause-play.png");
	play_button.setTexture(&play_pic);
	play_sprite.setTexture(play_pic);
	play_sprite.setOrigin(25, 25);
	play_sprite.setPosition(400, 550);



	backward_button.setSize(sf::Vector2f(75, 75));
	backward_button.setOrigin(25, 25);
	backward_button.setPosition(300, 540);
	backward_pic.loadFromFile("previous.png");
	backward_button.setTexture(&backward_pic);
	backward_sprite.setTexture(backward_pic);
	backward_sprite.setOrigin(25, 25);
	backward_sprite.setPosition(300, 550);




	forward_button.setSize(sf::Vector2f(75, 75));
	forward_button.setOrigin(25, 25);
	forward_button.setPosition(500, 540);
	forward_pic.loadFromFile("next.png");
	forward_button.setTexture(&forward_pic);
	forward_sprite.setTexture(forward_pic);
	forward_sprite.setOrigin(25, 25);
	forward_sprite.setPosition(500, 550);



	shuffle_button.setSize(sf::Vector2f(75, 75));
	shuffle_button.setOrigin(37.5, 37.5);
	shuffle_button.setPosition(150, 550);
	shuffle_pic.loadFromFile("shuffle.png");
	shuffle_button.setTexture(&shuffle_pic);
	shuffle_sprite.setTexture(shuffle_pic);
	shuffle_sprite.setPosition(150, 550);
	shuffle_sprite.setOrigin(12.5, 12.5);






	songs_list.setSize(sf::Vector2f(200, 50));

	songs_list.setPosition(0, 0);
	song_pic.loadFromFile("songs 200  unpressed.png");
	songs_list.setTexture(&song_pic);
	song_sprite.setTexture(song_pic);
	song_sprite.setPosition(0, 0);



	artist_list.setSize(sf::Vector2f(200, 50));

	artist_list.setPosition(200, 0);
	artist_pic.loadFromFile("artists unpressed.png");
	artist_list.setTexture(&artist_pic);
	artist_sprite.setTexture(artist_pic);
	artist_sprite.setPosition(200, 0);





	album_list.setSize(sf::Vector2f(200, 50));
	album_list.setPosition(400, 0);
	album_pic.loadFromFile("albums unpressed.png");
	album_list.setTexture(&album_pic);
	album_sprite.setTexture(album_pic);
	album_sprite.setPosition(400, 0);



	genre_list.setSize(sf::Vector2f(200, 50));

	genre_list.setPosition(600, 0);
	genre_pic.loadFromFile("genres  pressed.png");
	genre_list.setTexture(&genre_pic);
	genre_sprite.setTexture(genre_pic);
	genre_sprite.setPosition(600, 0);





	back_pic.setSize(sf::Vector2f(800.0f, 600.0f));
	background_texture.loadFromFile("wallpaper dark final final.png");
	if (!background_texture.loadFromFile("wallpaper dark final final.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(shuffle_button);
	window.draw(genre_list);
	window.draw(search_box);
	window.draw(album_list);
	window.draw(songs_list);
	window.draw(artist_list);
	window.draw(backward_button);
	window.draw(forward_button);
	window.draw(play_button);
	for (int i = 0; i <= 13; i++) {
		window.draw(genre[i]);
		window.draw(name_genre[i]);
	}



	if (focus(album_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "album";

		}
	}
	if (focus(song_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "song";

		}
	}
	if (focus(artist_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "artist";

		}
	}



	/////// search button pressing
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}


	//////////////string to search for 
	if (focus(search_sprite.getGlobalBounds(), mouse_position) && mouse_position.x < 560) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {


		}
	}
}





void datapage(sf::RenderWindow& window, sf::Event& event, string& mod, sf::Vector2f& mouse_position)
{
	window.clear();
	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape done_button;
	sf::Texture done_texture;
	sf::Sprite donesprite;

	done_button.setSize(sf::Vector2f(165, 96));
	done_button.setOrigin(85, 143);
	done_button.setPosition(300, 375);
	done_texture.loadFromFile("done button - Copy.png");
	done_button.setTexture(&done_texture);
	donesprite.setTexture(done_texture);
	donesprite.setOrigin(85, 143);
	donesprite.setPosition(300, 375);


	back_pic.setSize(sf::Vector2f(600.0f, 300.0f));
	background_texture.loadFromFile("datawindow - Copy.png");
	if (!background_texture.loadFromFile("datawindow - Copy.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(done_button);

	if (focus(done_button.getGlobalBounds(), mouse_position))
	{
		if (event.type == sf::Event::MouseButtonPressed &&event.mouseButton.button == sf::Mouse::Left)
		{
			window.close();
		}
	}
}


void wpage(sf::RenderWindow& window, sf::Event& event, string& mod, sf::Vector2f& mouse_position)
{
	window.clear();
	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape login_button;
	sf::Texture login_texture;
	sf::RectangleShape sign_button;
	sf::Texture sign_texture;
	sf::Sprite loginsprite;
	sf::Sprite signsprite;

	login_button.setSize(sf::Vector2f(165, 96));
	login_button.setOrigin(85, 143);
	login_button.setPosition(263, 244);
	login_texture.loadFromFile("login button.png");
	login_button.setTexture(&login_texture);
	loginsprite.setTexture(login_texture);
	loginsprite.setOrigin(85, 143);
	loginsprite.setPosition(263, 244);


	sign_button.setSize(sf::Vector2f(165, 96));
	sign_button.setOrigin(83, 143);
	sign_button.setPosition(100, 244);
	sign_texture.loadFromFile("sign up.png");
	sign_button.setTexture(&sign_texture);
	signsprite.setTexture(sign_texture);
	signsprite.setOrigin(83, 143);
	signsprite.setPosition(100, 244);


	back_pic.setSize(sf::Vector2f(600.0f, 300.0f));
	background_texture.loadFromFile("welcoming page clean.png");
	if (!background_texture.loadFromFile("welcoming page clean.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);

	window.draw(back_pic);
	window.draw(login_button);
	window.draw(sign_button);

	if (focus(login_button.getGlobalBounds(), mouse_position))
	{
		if (event.type == sf::Event::MouseButtonPressed &&event.mouseButton.button == sf::Mouse::Left)
		{
			mod = "login";
		}
	}

	if (focus(sign_button.getGlobalBounds(), mouse_position))
	{
		if (event.type == sf::Event::MouseButtonPressed &&event.mouseButton.button == sf::Mouse::Left)
		{
			mod = "sign up";
		}
	}
	




	//////////////////////////////// name to be entered /////////////////// / / / / / / * * * 8* /- *8 65 43 63 132 132 
	string name = ""; 
	sf::Text username;
	sf::Font font; 
	username.setPosition(200, 200); 
	username.setCharacterSize(24); 
	font.loadFromFile("Roboto-ThinItalic.ttf");
	username.setFont(font); 
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode < 128 && event.text.unicode != 8) {
			name += event.text.unicode;
			username.setString(name); 
		}
		if (event.text.unicode == 8) {
			name.erase(name.begin() + (name.size() - 1)); 
			username.setString(name);
		}
	}
	window.draw(username); 

}
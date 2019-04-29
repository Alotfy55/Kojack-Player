#pragma once
#include "Fuctions.h"
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


struct second_window {
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
	sf::CircleShape search_box;
	sf::Texture search_box_pic;
	sf::Text seacr_text;
	sf::RectangleShape rating_bar;
	RectangleShape music_box[20];
	Text name_music[20];
	Font use_font;
	sf::RectangleShape sorting_button[2];
	sf::Texture sorting_pic[2];
	sf::Texture rating_pic;
	RectangleShape clickin_result[20];
	Text clicking_result_text[20];
}Playing_window;

struct First_window2 {
	sf::Font myfont;
	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape done_button;
	sf::Texture done_texture;
	sf::Sprite donesprite;
	std::string userinput;
	sf::Text username;
	sf::RectangleShape usertextbox;
	sf::RectangleShape pwtextbox;
	sf::Text password;
	std::string pwinput;
	string shown_password = "";
	sf::Text error_message[2];
	sf::Font error_message_font;

}welcoming_window;


struct First_window1 {
	sf::RectangleShape back_pic;
	sf::Texture background_texture;
	sf::RectangleShape login_button;
	sf::Texture login_texture;
	sf::RectangleShape sign_button;
	sf::Texture sign_texture;
	sf::Sprite loginsprite;
	sf::Sprite signsprite;
} openning;

struct search_window {
	RectangleShape searching_results_box[10];
	RectangleShape search_text_box;
	Text search_text;
	Text text_searching_results[10];
	Texture search_bar_texture;
	RectangleShape title_button_search[4];
	Text title_name_button_search[4];
	
	Font use_font;
	////////////// wallpaper ////////
	Sprite sprite;
	Texture texture;
	Vector2u size = texture.getSize();
}while_serching;


//////// Gui Functions Decleration ///*****

void wpage(sf::RenderWindow& window, sf::Event& event);
bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position);
void song_tab(sf::RenderWindow& window, sf::Event& event);


void searching_window(); 
void show_welcome_window();
void Show_main_program();
void drawing_list_of_anything(vector<string> to_be_shown  , float x_position, bool left);
void displaying_list_of_anything(vector<string>to_be_shown, sf::RenderWindow& window);

void showing_songs_after_clicking(sf::Event& event, vector<string> to_be_shown, int choice);
void play_music_by_clicking(sf::Event& event);

//////// Gui Functions Decleration ///*****

void show_welcome_window() {
	mod = "welcome";
	sf::RenderWindow starting_window(sf::VideoMode(600, 300), "Kojack Player", sf::Style::Default);



	welcoming_window.error_message_font.loadFromFile(Imgs_directory"Roboto-ThinItalic.ttf");
	welcoming_window.error_message[0].setFont(welcoming_window.error_message_font);
	welcoming_window.error_message[0].setCharacterSize(25);
	welcoming_window.error_message[0].setFillColor(sf::Color::Red);
	welcoming_window.error_message[0].setStyle(sf::Text::Bold);
	welcoming_window.error_message[0].setPosition(50, 135);
	welcoming_window.error_message[0].setString("Username already taken");



	welcoming_window.error_message[1].setFont(welcoming_window.error_message_font);
	welcoming_window.error_message[1].setCharacterSize(25);
	welcoming_window.error_message[1].setFillColor(sf::Color::Red);
	welcoming_window.error_message[1].setStyle(sf::Text::Bold);
	welcoming_window.error_message[1].setPosition(50, 205);
	welcoming_window.error_message[1].setString("Invalid username or password");


	welcoming_window.usertextbox.setSize(sf::Vector2f(175, 21));
	welcoming_window.usertextbox.setOrigin(85, 143);
	welcoming_window.usertextbox.setPosition(265, 242);


	welcoming_window.pwtextbox.setSize(sf::Vector2f(175, 21));
	welcoming_window.pwtextbox.setOrigin(85, 143);
	welcoming_window.pwtextbox.setPosition(265, 319);


	welcoming_window.done_button.setSize(sf::Vector2f(165, 96));
	welcoming_window.done_button.setOrigin(85, 143);
	welcoming_window.done_button.setPosition(300, 375);
	welcoming_window.done_texture.loadFromFile(Imgs_directory"done button.png");
	welcoming_window.done_button.setTexture(&welcoming_window.done_texture);
	welcoming_window.donesprite.setTexture(welcoming_window.done_texture);
	welcoming_window.donesprite.setOrigin(85, 143);
	welcoming_window.donesprite.setPosition(300, 375);

	welcoming_window.myfont.loadFromFile(Imgs_directory"parkway lush.ttf");
	welcoming_window.username.setFont(welcoming_window.myfont);
	welcoming_window.username.setFillColor(sf::Color::Blue);
	welcoming_window.username.setPosition(265, 235);
	welcoming_window.username.setOrigin(85, 143);


	welcoming_window.password.setFont(welcoming_window.myfont);
	welcoming_window.password.setFillColor(sf::Color::Blue);
	welcoming_window.password.setPosition(265, 311);
	welcoming_window.password.setOrigin(85, 143);



	welcoming_window.back_pic.setSize(sf::Vector2f(600.0f, 300.0f));
	welcoming_window.background_texture.loadFromFile(Imgs_directory"datawindow.png");
	if (!welcoming_window.background_texture.loadFromFile(Imgs_directory"datawindow.png")) {
		cout << "error while loading the background";
	}
	welcoming_window.back_pic.setTexture(&welcoming_window.background_texture);
	int windicator = 0;
	while (starting_window.isOpen())
	{
		sf::Event starting;
		while (starting_window.pollEvent(starting))
		{

			if (starting.type == sf::Event::Closed) {
				starting_window.close();
				//return 0;
			}
			mouse_position.x = sf::Mouse::getPosition(starting_window).x;
			mouse_position.y = sf::Mouse::getPosition(starting_window).y;
			
			if (mod == "welcome")
			{
				starting_window.clear();
				
				wpage(starting_window, starting);

			}
			if (mod == "login")
			{
				starting_window.clear();
				starting_window.draw(welcoming_window.back_pic);
				starting_window.draw(welcoming_window.done_button);
				starting_window.draw(welcoming_window.usertextbox);
				starting_window.draw(welcoming_window.pwtextbox);
				if (focus(welcoming_window.usertextbox.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						windicator = 1;
					}
				}
				if (focus(welcoming_window.pwtextbox.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						windicator = 2;
					}
				}
				if (starting.type == sf::Event::TextEntered)
				{
					if (starting.text.unicode < 128 && starting.text.unicode != 8 && windicator == 1)
					{
						welcoming_window.userinput += starting.text.unicode;
						welcoming_window.username.setString(welcoming_window.userinput);
					}
					if (starting.text.unicode == 8 && welcoming_window.userinput.size() > 0 && windicator == 1)
					{
						welcoming_window.userinput.erase(welcoming_window.userinput.begin() + welcoming_window.userinput.size() - 1);
						welcoming_window.username.setString(welcoming_window.userinput);
					}

				}
				starting_window.draw(welcoming_window.username);
				if (starting.type == sf::Event::TextEntered)
				{
					if (starting.text.unicode < 128 && starting.text.unicode != 8 && windicator == 2)
					{
						welcoming_window.pwinput += starting.text.unicode;
						welcoming_window.shown_password += "*";
						welcoming_window.password.setString(welcoming_window.shown_password);
					}
					else if (starting.text.unicode == 8 && welcoming_window.pwinput.size() > 0 && windicator == 2 && welcoming_window.shown_password.size() > 0)
					{
						welcoming_window.pwinput.erase(welcoming_window.pwinput.begin() + welcoming_window.pwinput.size() - 1);
						welcoming_window.shown_password.erase(welcoming_window.shown_password.size() - 1);
						welcoming_window.password.setString(welcoming_window.shown_password);
					}


				}
				starting_window.draw(welcoming_window.password);
				if (focus(welcoming_window.done_button.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						if (login(welcoming_window.userinput, welcoming_window.pwinput) == true) {
							starting_window.close();
						}
						else {
							starting_window.draw(welcoming_window.error_message[1]);
						}
					}
				}
			}
			if (mod == "sign up")
			{

				starting_window.clear();
				starting_window.draw(welcoming_window.back_pic);
				starting_window.draw(welcoming_window.done_button);
				starting_window.draw(welcoming_window.usertextbox);
				starting_window.draw(welcoming_window.pwtextbox);
				if (focus(welcoming_window.usertextbox.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						windicator = 1;
					}
				}
				if (focus(welcoming_window.pwtextbox.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						windicator = 2;
					}
				}
				if (starting.type == sf::Event::TextEntered)
				{
					if (starting.text.unicode < 128 && starting.text.unicode != 8 && windicator == 1)
					{
						welcoming_window.userinput += starting.text.unicode;
						welcoming_window.username.setString(welcoming_window.userinput);
					}
					if (starting.text.unicode == 8 && welcoming_window.userinput.size() > 0 && windicator == 1)
					{
						welcoming_window.userinput.erase(welcoming_window.userinput.begin() + welcoming_window.userinput.size() - 1);
						welcoming_window.username.setString(welcoming_window.userinput);
					}

				}
				starting_window.draw(welcoming_window.username);
				if (starting.type == sf::Event::TextEntered)
				{
					if (starting.text.unicode < 128 && starting.text.unicode != 8 && windicator == 2)
					{
						welcoming_window.pwinput += starting.text.unicode;
						welcoming_window.shown_password += "*";
						welcoming_window.password.setString(welcoming_window.shown_password);
					}
					else if (starting.text.unicode == 8 && welcoming_window.pwinput.size() > 0 && windicator == 2 && welcoming_window.shown_password.size() > 0)
					{
						welcoming_window.pwinput.erase(welcoming_window.pwinput.begin() + welcoming_window.pwinput.size() - 1);
						welcoming_window.shown_password.erase(welcoming_window.shown_password.size() - 1);
						welcoming_window.password.setString(welcoming_window.shown_password);
					}


				}
				starting_window.draw(welcoming_window.password);
				if (focus(welcoming_window.done_button.getGlobalBounds(), mouse_position))
				{
					if (starting.type == sf::Event::MouseButtonPressed &&starting.mouseButton.button == sf::Mouse::Left)
					{
						if (signup(welcoming_window.userinput, welcoming_window.pwinput) == true)
							starting_window.close();
						else {
							starting_window.draw(welcoming_window.error_message[0]);
						}
					}
				}
			}
			starting_window.display();
			starting_window.clear();

		}

	}
}

void Show_main_program() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Kojack Player", sf::Style::Default);
	window.setKeyRepeatEnabled(false);
	mod = "song";
	READ_RATING();
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
			
		}
			song_tab(window,  event);
		
		window.display();
		window.clear();


	}
}

void wpage(sf::RenderWindow& window, sf::Event& event)
{
	window.clear();


	openning.login_button.setSize(sf::Vector2f(165, 96));
	openning.login_button.setOrigin(85, 143);
	openning.login_button.setPosition(263, 244);
	openning.login_texture.loadFromFile(Imgs_directory"login button.png");
	openning.login_button.setTexture(&openning.login_texture);
	openning.loginsprite.setTexture(openning.login_texture);
	openning.loginsprite.setOrigin(85, 143);
	openning.loginsprite.setPosition(263, 244);


	openning.sign_button.setSize(sf::Vector2f(165, 96));
	openning.sign_button.setOrigin(83, 143);
	openning.sign_button.setPosition(100, 244);
	openning.sign_texture.loadFromFile(Imgs_directory"sign up.png");
	openning.sign_button.setTexture(&openning.sign_texture);
	openning.signsprite.setTexture(openning.sign_texture);
	openning.signsprite.setOrigin(83, 143);
	openning.signsprite.setPosition(100, 244);


	openning.back_pic.setSize(sf::Vector2f(600.0f, 300.0f));
	openning.background_texture.loadFromFile(Imgs_directory"welcoming page clean.png");
	if (!openning.background_texture.loadFromFile(Imgs_directory"welcoming page clean.png")) {
		cout << "error while loading the background";
	}
	openning.back_pic.setTexture(&openning.background_texture);

	window.draw(openning.back_pic);
	window.draw(openning.login_button);
	window.draw(openning.sign_button);

	if (focus(openning.login_button.getGlobalBounds(), mouse_position))
	{
		if (event.type == sf::Event::MouseButtonPressed &&event.mouseButton.button == sf::Mouse::Left)
		{
			mod = "login";
		}
	}

	if (focus(openning.sign_button.getGlobalBounds(), mouse_position))
	{
		if (event.type == sf::Event::MouseButtonPressed &&event.mouseButton.button == sf::Mouse::Left)
		{
			mod = "sign up";
		}
	}









}

bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position) {
	if (sprite.contains(mouse_position)) {

		return true;
	}
	return false;
}

void drawing_list_of_anything(vector<string> to_be_shown ,  float hello   , bool left  ) {
	Playing_window.use_font.loadFromFile(Imgs_directory"Roboto-ThinItalic.ttf");


	float y = 55;
	for (int i = 0; i < to_be_shown.size(); ++i) {
		Playing_window.music_box[i].setSize(Vector2f(200, 30));
		Playing_window.music_box[i].setPosition(hello, y);
		Playing_window.music_box[i].setFillColor(Color::Transparent);
		Playing_window.name_music[i].setFont(Playing_window.use_font);
		Playing_window.name_music[i].setStyle(Text::Bold);

		if (mod == "song") {

			if (is_songs_sorted) {
				Playing_window.name_music[i].setString(sorted_songs[i]);

			}
			else {
				Playing_window.name_music[i].setString(songs[i]);
			}
			if (i == index_of_playing_song && !shufflle) {
				Playing_window.name_music[i].setColor(Color::Magenta);
			}
			else {
				Playing_window.name_music[i].setColor(sf::Color::Blue);
			}
			Playing_window.name_music[i].setPosition(hello, y);
			Playing_window.name_music[i].setCharacterSize(24);

		}
		else {
			Playing_window.name_music[i].setString(to_be_shown[i]);
			Playing_window.name_music[i].setPosition(hello, y);
			if (!left) {

				Playing_window.name_music[i].setFillColor(sf::Color::Magenta);
			}
			else {
				Playing_window.name_music[i].setFillColor(sf::Color::Blue);
			}

		}
		y += 33;



	}


}

void displaying_list_of_anything(vector<string>to_be_shown, sf::RenderWindow& window) {
	for (int i = 0; i < to_be_shown.size(); i++) {
		window.draw(Playing_window.music_box[i]);
		window.draw(Playing_window.name_music[i]);
	}
}

void showing_songs_after_clicking(sf::Event& event, vector<string> to_be_shown, int choice) {
	for (int i = 0; i < to_be_shown.size(); ++i) {
		if (focus(Playing_window.music_box[i].getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				songs_by_a_default_thing = View_song(choice, to_be_shown[i]);

			}
		}

	}
}


void play_music_by_clicking(sf::Event& event) {
	for (int i = 0; i < songs_by_a_default_thing.size(); ++i) {
		if (focus(Playing_window.music_box[i].getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				playMusic(songs_by_a_default_thing[i]);
				songs_by_a_default_thing.clear();
			}
		}
	}
}

void song_tab(sf::RenderWindow& window, sf::Event& event) {
	window.clear();

	//// play button
	Playing_window.play_button.setSize(sf::Vector2f(75, 75));
	Playing_window.play_button.setOrigin(25, 25);
	Playing_window.play_button.setPosition(400, 540);
	Playing_window.play_pic.loadFromFile(Imgs_directory"pause-play.png");
	Playing_window.play_button.setTexture(&Playing_window.play_pic);
	Playing_window.play_sprite.setTexture(Playing_window.play_pic);
	Playing_window.play_sprite.setOrigin(25, 25);
	Playing_window.play_sprite.setPosition(400, 550);

	//// back picture 
	Playing_window.back_pic.setSize(sf::Vector2f(800.0f, 600.0f));
	Playing_window.background_texture.loadFromFile(Imgs_directory"wallpaper dark final final.png");
	if (!Playing_window.background_texture.loadFromFile(Imgs_directory"wallpaper dark final final.png")) {
		cout << "error while loading the background";
	}
	Playing_window.back_pic.setTexture(&Playing_window.background_texture);


	Playing_window.songs_list.setSize(sf::Vector2f(200, 50));
	Playing_window.songs_list.setPosition(0, 0);
	if (mod == "song") {
		Playing_window.song_pic.loadFromFile(Imgs_directory"songs  pressed.png");

	}
	else {
		Playing_window.song_pic.loadFromFile(Imgs_directory"songs 200  unpressed.png");

	}
	Playing_window.songs_list.setTexture(&Playing_window.song_pic);
	Playing_window.song_sprite.setTexture(Playing_window.song_pic);
	Playing_window.song_sprite.setPosition(0, 0);



	Playing_window.artist_list.setSize(sf::Vector2f(200, 50));
	Playing_window.artist_list.setPosition(200, 0);
	if (mod == "artist") {
		Playing_window.artist_pic.loadFromFile(Imgs_directory"artists pressed.png");
	}
	else {
		Playing_window.artist_pic.loadFromFile(Imgs_directory"artists unpressed.png");
	}
	Playing_window.artist_list.setTexture(&Playing_window.artist_pic);
	Playing_window.artist_sprite.setTexture(Playing_window.artist_pic);
	Playing_window.artist_sprite.setPosition(200, 0);





	Playing_window.album_list.setSize(sf::Vector2f(200, 50));
	Playing_window.album_list.setPosition(400, 0);
	if (mod == "album") {
		Playing_window.album_pic.loadFromFile(Imgs_directory"albums pressed.png");
	}
	else {
		Playing_window.album_pic.loadFromFile(Imgs_directory"albums unpressed.png");
	}
	Playing_window.album_list.setTexture(&Playing_window.album_pic);
	Playing_window.album_sprite.setTexture(Playing_window.album_pic);
	Playing_window.album_sprite.setPosition(400, 0);



	Playing_window.genre_list.setSize(sf::Vector2f(200, 50));
	Playing_window.genre_list.setPosition(600, 0);
	if (mod == "genre") {
		Playing_window.genre_pic.loadFromFile(Imgs_directory"genres  pressed.png");
	}
	else {
		Playing_window.genre_pic.loadFromFile(Imgs_directory"genres unpressed.png");
	}
	Playing_window.genre_list.setTexture(&Playing_window.genre_pic);
	Playing_window.genre_sprite.setTexture(Playing_window.genre_pic);
	Playing_window.genre_sprite.setPosition(600, 0);



	Playing_window.backward_button.setSize(sf::Vector2f(75, 75));
	Playing_window.backward_button.setOrigin(25, 25);
	Playing_window.backward_button.setPosition(300, 540);
	Playing_window.backward_pic.loadFromFile(Imgs_directory"previous.png");
	Playing_window.backward_button.setTexture(&Playing_window.backward_pic);
	Playing_window.backward_sprite.setTexture(Playing_window.backward_pic);
	Playing_window.backward_sprite.setOrigin(25, 25);
	Playing_window.backward_sprite.setPosition(300, 550);




	Playing_window.forward_button.setSize(sf::Vector2f(75, 75));
	Playing_window.forward_button.setOrigin(25, 25);
	Playing_window.forward_button.setPosition(500, 540);
	Playing_window.forward_pic.loadFromFile(Imgs_directory"next.png");
	Playing_window.forward_button.setTexture(&Playing_window.forward_pic);
	Playing_window.forward_sprite.setTexture(Playing_window.forward_pic);
	Playing_window.forward_sprite.setOrigin(25, 25);
	Playing_window.forward_sprite.setPosition(500, 550);



	Playing_window.shuffle_button.setSize(sf::Vector2f(60, 60));
	Playing_window.shuffle_button.setOrigin(37.5, 37.5);
	Playing_window.shuffle_button.setPosition(145, 565);
	
	
	if (!shufflle) {
		Playing_window.shuffle_pic.loadFromFile(Imgs_directory"not shuffled.png");
	}
	else {
		Playing_window.shuffle_pic.loadFromFile(Imgs_directory"shuffled.png");
	}
	Playing_window.shuffle_button.setTexture(&Playing_window.shuffle_pic);
	Playing_window.shuffle_sprite.setTexture(Playing_window.shuffle_pic);
	Playing_window.shuffle_sprite.setPosition(145, 570);
	Playing_window.shuffle_sprite.setOrigin(12.5, 12.5);



	Playing_window.use_font.loadFromFile(Imgs_directory"Roboto-ThinItalic.ttf");
	Playing_window.sorting_button[0].setSize(sf::Vector2f(50, 75));
	Playing_window.sorting_pic[0].loadFromFile(Imgs_directory"arrow dn.png");
	Playing_window.sorting_button[0].setPosition(550, 100);
	Playing_window.sorting_button[0].setTexture(&Playing_window.sorting_pic[0]);
	Playing_window.sorting_button[0].setFillColor(sf::Color::Yellow);


	Playing_window.sorting_button[1].setSize(sf::Vector2f(50, 75));
	Playing_window.sorting_pic[1].loadFromFile(Imgs_directory"arrow up.png");
	Playing_window.sorting_button[1].setPosition(500, 100);
	Playing_window.sorting_button[1].setTexture(&Playing_window.sorting_pic[1]);
	Playing_window.sorting_button[1].setFillColor(sf::Color::Magenta);


	Playing_window.search_box.setRadius(30);
	Playing_window.search_box.setPosition(10, 530);
	
	Playing_window.search_box_pic.loadFromFile(Imgs_directory"Searh icon.png");
	Playing_window.search_box.setTexture(&Playing_window.search_box_pic); 
	
	if (focus(Playing_window.search_box.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			searching_window();
		}
	}


	Playing_window.rating_bar.setSize(sf::Vector2f(200, 40));
	Playing_window.rating_bar.setPosition(600, 535);
	Playing_window.rating_pic.loadFromFile(Imgs_directory"rating 0.png");
	Playing_window.rating_bar.setTexture(&Playing_window.rating_pic);

	window.draw(Playing_window.back_pic);


	if (mod == "song") {
		window.draw(Playing_window.search_box); 
		/////show list of songs 
		drawing_list_of_anything(songs, 0, true);


		///// rating and showing the rate 
		if (rating == 1)
		{
			Playing_window.rating_pic.loadFromFile(Imgs_directory"rating1.png");
		}
		if (rating == 2)
		{
			Playing_window.rating_pic.loadFromFile(Imgs_directory"rating2.png");
		}
		if (rating == 3)
		{
			Playing_window.rating_pic.loadFromFile(Imgs_directory"rating3.png");
		}
		if (rating == 4)
		{
			Playing_window.rating_pic.loadFromFile(Imgs_directory"rating4.png");
		}
		if (rating == 5)
		{
			Playing_window.rating_pic.loadFromFile(Imgs_directory"rating5.png");
		}
		if (focus(Playing_window.rating_bar.getGlobalBounds(), mouse_position) && mouse_position.x > 600 && mouse_position.x < 635)
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				rating = 1;
				rate(playing_song_name, rating);

			}
		}
		if (focus(Playing_window.rating_bar.getGlobalBounds(), mouse_position) && mouse_position.x > 640 && mouse_position.x < 675)
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				rating = 2;
				rate(playing_song_name, rating);
			}
		}
		if (focus(Playing_window.rating_bar.getGlobalBounds(), mouse_position) && mouse_position.x > 680 && mouse_position.x < 715)
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				rating = 3;
				rate(playing_song_name, rating);
			}
		}
		if (focus(Playing_window.rating_bar.getGlobalBounds(), mouse_position) && mouse_position.x > 720 && mouse_position.x < 755)
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				rating = 4;
				rate(playing_song_name, rating);
			}
		}
		if (focus(Playing_window.rating_bar.getGlobalBounds(), mouse_position) && mouse_position.x > 760 && mouse_position.x < 795)
		{
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				rating = 5;
				rate(playing_song_name, rating);
			}
		}
		/////// ending rating ///// 

		/////// enabling shuffle 
		shuffle(songs);
		if (focus(Playing_window.shuffle_button.getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				if (shufflle) {
					shufflle = false;
				}
				else {
					shufflle = true;
				}

			}
		}
		/////ending shuffle



		for (int i = 0; i < songs.size(); i++) {

			if (focus(Playing_window.music_box[i].getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					if (shufflle == false) {
						if (!is_songs_sorted) {
							index_of_playing_song = i;
							playMusic(songs[index_of_playing_song]);
							playing_song_name = songs[index_of_playing_song];
							get_Rating_for_current_song(playing_song_name);
						}
						else {
							index_of_playing_song = i;
							playMusic(sorted_songs[index_of_playing_song]);
							playing_song_name = sorted_songs[index_of_playing_song];
							get_Rating_for_current_song(playing_song_name);
						}
					}

					if (shufflle) {
						index_of_playing_song = shuffled[index_of_playing_song];
						playMusic(songs[shuffled[index_of_playing_song]]);
						playing_song_name = songs[shuffled[index_of_playing_song]];
					}
				}
			}


		}


		if (focus(Playing_window.backward_sprite.getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				index_of_playing_song--;

				if (shufflle == false) {
					check_order(index_of_playing_song);
					playMusic(songs[index_of_playing_song]);
					get_Rating_for_current_song(songs[index_of_playing_song]);

				}
				else {
					index_of_playing_song = shuffled[index_of_playing_song];
					playMusic(songs[shuffled[index_of_playing_song]]);

				}
			}
		}


		if (focus(Playing_window.forward_sprite.getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {

				index_of_playing_song++;
				if (shufflle == false) {

					check_order(index_of_playing_song);
					playMusic(songs[index_of_playing_song]);
					get_Rating_for_current_song(songs[index_of_playing_song]);
				}
				else {
					check_order(index_of_playing_song);
					playMusic(songs[shuffled[index_of_playing_song]]);
				}
			}
		}
		if (music.getStatus() == sf::SoundSource::Stopped && playing) {
			index_of_playing_song++;
			if (shufflle == false) {

				check_order(index_of_playing_song);
				playMusic(songs[index_of_playing_song]);
			}
			else {
				check_order(index_of_playing_song);
				playMusic(songs[shuffled[index_of_playing_song]]);
			}
		}


		// from high to low 
		if (focus(Playing_window.sorting_button[0].getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				if (is_songs_sorted == 0 || is_songs_sorted == -1) {
					is_songs_sorted = 1;
					sorted_songs = sorting(1);
				}
				else if (is_songs_sorted == 1) {
					is_songs_sorted = 0;
				}
			}
		}
		if (focus(Playing_window.sorting_button[1].getGlobalBounds(), mouse_position)) {
			if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
				if (is_songs_sorted == 0 || is_songs_sorted == 1) {
					is_songs_sorted = -1;
					sorted_songs = sorting(2);
				}
				else if (is_songs_sorted == -1) {
					is_songs_sorted = 0;
				}
			}
		}



		window.draw(Playing_window.shuffle_button);
		window.draw(Playing_window.backward_button);
		window.draw(Playing_window.forward_button);
		window.draw(Playing_window.sorting_button[0]);
		window.draw(Playing_window.sorting_button[1]);
		window.draw(Playing_window.rating_bar);
		window.draw(Playing_window.search_box);
		displaying_list_of_anything(songs, window);


	}
	else if (mod == "artist") {
		vector<string> to_be_shown = View_all(1);
		displaying_list_of_anything(to_be_shown, window);
		drawing_list_of_anything(to_be_shown, 0, true);
		displaying_list_of_anything(to_be_shown, window);
		showing_songs_after_clicking(event, to_be_shown, 2);
		drawing_list_of_anything(songs_by_a_default_thing, 300, false);
		displaying_list_of_anything(songs_by_a_default_thing, window);
		play_music_by_clicking(event);

	}
	else if (mod == "album") {
		vector<string> to_be_shown = View_all(3);
		displaying_list_of_anything(to_be_shown, window);
		drawing_list_of_anything(to_be_shown, 0, true);
		displaying_list_of_anything(to_be_shown, window);
		showing_songs_after_clicking(event, to_be_shown, 1);
		drawing_list_of_anything(songs_by_a_default_thing, 300, false);
		displaying_list_of_anything(songs_by_a_default_thing, window);
		play_music_by_clicking(event);

	}
	else if (mod == "genre") {
		vector<string> to_be_shown = View_all(2);
		displaying_list_of_anything(to_be_shown, window);
		drawing_list_of_anything(to_be_shown, 0, true);
		displaying_list_of_anything(to_be_shown, window);
		showing_songs_after_clicking(event, to_be_shown, 3);
		drawing_list_of_anything(songs_by_a_default_thing, 300, false);
		displaying_list_of_anything(songs_by_a_default_thing, window);
		play_music_by_clicking(event);

	}
	//////////play button pressing
	if (focus(Playing_window.play_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			if (playing == true) {
				music.pause();
				playing = false;
			}
			else {
				music.play();
				playing = true;

			}
		}
	}
	/////ending play 
	window.draw(Playing_window.play_button);
	window.draw(Playing_window.genre_list);
	window.draw(Playing_window.artist_list);
	window.draw(Playing_window.album_list);
	window.draw(Playing_window.songs_list);



	///// to jump between tabs ///
	if (focus(Playing_window.song_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "song";
			songs_by_a_default_thing.clear();
		}
	}
	if (focus(Playing_window.album_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "album";
			songs_by_a_default_thing.clear();
		}
	}
	if (focus(Playing_window.genre_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "genre";
			songs_by_a_default_thing.clear();
		}
	}
	if (focus(Playing_window.artist_sprite.getGlobalBounds(), mouse_position)) {
		if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left) {
			mod = "artist";
			songs_by_a_default_thing.clear();
		}
	}
	//// end jumping //



}

void searching_window() {
	//////////////////search_window///////////////////////////////////////

	sf::RenderWindow Searchwindow(sf::VideoMode(500, 500), "<Search_Window>");
	Searchwindow.clear();
	while_serching.texture.loadFromFile(Imgs_directory"kojackplayer_background.png");
	while_serching.sprite.setTexture(while_serching.texture);
	//////////////////////////////////

	///////// title_button///////

	////////////////////

	//////// boxes bta3t results search w text bta3tha

	while_serching.use_font.loadFromFile(Imgs_directory"Roboto-ThinItalic.ttf");
	while_serching.search_bar_texture.loadFromFile(Imgs_directory"search bar.png");
	//////////////////////////
	int year_to_searched_for = 0;

	////////////////// button bta3 search eli hua kan fy elawl kunt 7att feh sort done//////////////

	///////////////////////////////////////////////////////////////////////////////////


	int searchicator = 0;

	////////   search bar && text search bar ///////////
	while_serching.search_text.setCharacterSize(16);
	while_serching.search_text.setFont(while_serching.use_font);
	while_serching.search_text.setFillColor(sf::Color::Black);
	while_serching.search_text.setPosition(200, 50);
	while_serching.search_text.setStyle(Text::Bold);
	while_serching.search_text.setCharacterSize(28);
	while_serching.search_text_box.setSize(Vector2f(350, 40));
	while_serching.search_text_box.setPosition(130, 50);
	while_serching.search_text_box.setFillColor(Color::White);
	while_serching.search_text_box.setTexture(&while_serching.search_bar_texture);
	//////////////////////////////////////////////





	///// button title ////
	while_serching.title_name_button_search[0].setString("  Name");
	while_serching.title_name_button_search[1].setString("Album");
	while_serching.title_name_button_search[2].setString("artist");
	while_serching.title_name_button_search[3].setString("year");
	float x = 5;
	for (int i = 0; i < 4; ++i) {
		while_serching.title_button_search[i].setSize(Vector2f(90, 40));
		while_serching.title_button_search[i].setPosition(x, 10);
		while_serching.title_button_search[i].setFillColor(Color::Transparent);
		while_serching.title_name_button_search[i].setFont(while_serching.use_font);
		while_serching.title_name_button_search[i].setStyle(Text::Bold);
		while_serching.title_name_button_search[i].setPosition(x, 10);
		while_serching.title_name_button_search[i].setCharacterSize(32);
		x += 130;



	}
	/////////////////////////


	while (Searchwindow.isOpen())
	{
		sf::Event starting_search;
		while (Searchwindow.pollEvent(starting_search)) {
			mouse_position.x = sf::Mouse::getPosition(Searchwindow).x;
			mouse_position.y = sf::Mouse::getPosition(Searchwindow).y;

			if (starting_search.type == sf::Event::Closed) {
				Searchwindow.close();
				searching_results.clear();
			}


			////////////text Entred/////////////
			if (starting_search.type == sf::Event::TextEntered)
			{
				if (starting_search.text.unicode < 128 && starting_search.text.unicode != 8)
				{
					userinput_search += starting_search.text.unicode;
					while_serching.search_text.setString(userinput_search);

				}
				if (starting_search.text.unicode == 8 && userinput_search.size() > 0)
				{
					userinput_search.erase(userinput_search.begin() + userinput_search.size() - 1);
					while_serching.search_text.setString(userinput_search);
				}
			}
			//////////////////////////////////////////////////////


			//////////////done_search function/////////////////////////


			if (focus(while_serching.search_text_box.getGlobalBounds(), mouse_position) && mouse_position.x < 195) {
				if (starting_search.type == sf::Event::MouseButtonPressed  && starting_search.mouseButton.button == sf::Mouse::Left) {
					{

						searching_results = search_display(userinput_search, searchicator);



					}


				}
			}
			///////////////////////////////////////////////////////////////


			///////////////// result_searching////////////////
			float y = 120;
			for (int i = 0; i < searching_results.size(); ++i) {
				while_serching.searching_results_box[i].setSize(Vector2f(110, 40));
				while_serching.searching_results_box[i].setPosition(6, y);
				while_serching.searching_results_box[i].setFillColor(Color::Transparent);
				while_serching.text_searching_results[i].setFont(while_serching.use_font);
				while_serching.text_searching_results[i].setStyle(Text::Bold);
				while_serching.text_searching_results[i].setColor(Color::Black);
				while_serching.text_searching_results[i].setPosition(6, y);
				while_serching.text_searching_results[i].setCharacterSize(22);
				while_serching.text_searching_results[i].setString(searching_results[i]);
				y += 45;
			}
			///////////////////////////////////////////////////////////////////


			//////////////title_button function////////////////////////////// 
			for (int i = 0; i < 4; i++) {
				if (focus(while_serching.title_button_search[i].getGlobalBounds(), mouse_position)) {
					if (starting_search.type == sf::Event::MouseButtonPressed  && starting_search.mouseButton.button == sf::Mouse::Left) {
						{
							searchicator = i;




						}


					}

				}
				///////  /////////////
				if (searchicator == i) {
					while_serching.title_name_button_search[i].setFillColor(sf::Color::Black);
				}
				else {
					while_serching.title_name_button_search[i].setFillColor(sf::Color::Blue);
				}
				//////////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////////



		/////////////playing button function/////////////////////////
			for (int i = 0; i < searching_results.size(); ++i) {
				if (focus(while_serching.text_searching_results[i].getGlobalBounds(), mouse_position)) {
					if (starting_search.type == sf::Event::MouseButtonPressed  && starting_search.mouseButton.button == sf::Mouse::Left) {
						playMusic(searching_results[i]);

					}
				}
			}
			///////////////////////////////////////////////////////
		}





		///////////////////Draw/////////////////////////
		Searchwindow.draw(while_serching.sprite);
		for (int i = 0; i < 4; i++) {
			Searchwindow.draw(while_serching.title_button_search[i]);
			Searchwindow.draw(while_serching.title_name_button_search[i]);

		}
		for (int i = 0; i < searching_results.size(); i++) {
			Searchwindow.draw(while_serching.searching_results_box[i]);
			Searchwindow.draw(while_serching.text_searching_results[i]);
		}
		for (int i = 0; i < 4; ++i) {
			if (searchicator == i) {
				Searchwindow.draw(while_serching.search_text_box);

			}
		}


		Searchwindow.draw(while_serching.search_text);
		Searchwindow.display();
		///////////////////////////////////////////////
	}

}





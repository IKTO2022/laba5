#pragma once
#include<windows.h>
using namespace std;

namespace N
{
	class RecordPlayer
	{
	private:
		// Model
		int version;

		// characteristic
		int decibell;
		int frequency; // Hz
		bool onoff;

	public:
		RecordPlayer();
		RecordPlayer(int version_input, int decibell_input, int frequency_input);
		~RecordPlayer();

		void turn_on();
		void turn_off();
		void set_bass_mode();
		void set_middle_mode();
		void set_vocal_mode();
		void make_more_bass(int frequency_input);
		void make_more_vocal(int frequency_input);
		void volume_up(int decibell_input);
		void volume_down(int decibell_input);
		void showSettings();
		bool IsTurnedOn();
	};



	RecordPlayer::RecordPlayer()
	{
		// Settings for middle mode
		version = 1000;
		decibell = 50;
		frequency = 500;
		onoff = false;
	}
	RecordPlayer::RecordPlayer(int version_input, int decibell_input, int frequency_input)
	{
		version = version_input;
		decibell = decibell_input;
		frequency = frequency_input;
		onoff = false;
	}

	RecordPlayer::~RecordPlayer()
	{

	}

	void RecordPlayer::turn_on()
	{
		if (onoff == false)
		{
			cout << "RecordPlayer is turning on" << endl;
			Sleep(500);
			cout << "3..." << endl;
			Sleep(500);
			cout << "2..." << endl;
			Sleep(500);
			cout << "1..." << endl;
			Sleep(500);
			cout << "RecordPlayer is ready to play music" << endl;
 			onoff = true;
		}
		else
		{
			cout << "RecordPlayer has already turned on" << endl;
		}
	}

	void RecordPlayer::turn_off()
	{
		cout << "RecordPlayer is turning off" << endl;
		Sleep(500);
		cout << "3..." << endl;
		Sleep(500);
		cout << "2..." << endl;
		Sleep(500);
		cout << "1..." << endl;
		Sleep(500);
		cout << "See you next time!" << endl;
		onoff = false;

	}

	void RecordPlayer::set_bass_mode()
	{
		decibell = 100;
		frequency = 400;
		cout << "You settered the bass mode" << endl;
		cout << "Current decibells are " << decibell << endl;
		cout << "Current frequency is " << frequency << endl;

	}

	void RecordPlayer::set_middle_mode()
	{
		decibell = 50;
		frequency = 1000;
		cout << "You settered the middle mode" << endl;
		cout << "Current decibells are " << decibell << endl;
		cout << "Current frequency is " << frequency << endl;

	}

	void RecordPlayer::set_vocal_mode()
	{
		decibell = 80;
		frequency = 10000;
		cout << "You settered the vocal mode" << endl;
		cout << "Current decibells are " << decibell << endl;
		cout << "Current frequency is " << frequency << endl;
	}

	void RecordPlayer::make_more_bass(int frequency_input)
	{
		if ((frequency + frequency_input) < 0)
		{
			cout << "Limit is 0. Do not break the limit" << endl;
		}
		else
		{
			frequency += frequency_input;
		}
		cout << "Current frequency is " << frequency << endl;
	}

	void RecordPlayer::make_more_vocal(int frequency_input)
	{
		if ((frequency + frequency_input) >= 15000)
		{
			cout << "Limit is 15000. Do not break the limit" << endl;
		}
		else
		{
			frequency += frequency_input;
		}
		cout << "Current frequency is " << frequency << endl;
	}

	void RecordPlayer::volume_up(int decibell_input)
	{
		if ((decibell + decibell_input) >= 100)
		{
			cout << "Limit is 15000. Do not break the limit" << endl;
		}
		else
		{
			decibell += decibell_input;
		}
		cout << "Current decibell is " << decibell << endl;
	}

	void RecordPlayer::volume_down(int decibell_input)
	{
		if ((decibell + decibell_input) < 0)
		{
			cout << "Limit is 0. Do not break the limit" << endl;
		}
		else
		{
			decibell += decibell_input;
		}
		cout << "Current decibell is " << decibell << endl;
	}

	void RecordPlayer::showSettings()
	{
		cout << "Vesrion of RecordPlayer is " << version << endl;
		cout << "Current decibell is " << decibell << endl;
		cout << "Current frequency is " << frequency << endl;
	}
	bool RecordPlayer::IsTurnedOn()
	{
		if (onoff == false)
		{
			cout << "Firstly, turn on the RecordPlayer" << endl;
		}
		return onoff;
	}
}
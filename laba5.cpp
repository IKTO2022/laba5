#include <iostream>
#include<windows.h>
#include "RecordPlayer.h"

using namespace std;
using namespace N;

void showMenu();
void prestartintro();


int main()
{
	int leaver = 0; // �������, ������������� �� "���������" ���������� ���������
	int counter = 0; // �������, ������������� �� ����� ���� �������������� � ������������ (����������)
	int helper = 0; // �������, ������������� �� ����������� �����, ����� ������������ ����� ���������� ��� ��������� �������� �����������
	int breaker = 1; // �������, ������������� �� ������ ����� �� ���������.
	int option = -1; // ���������� ��������� �������� � ����������.
	int change_volume = 0; 
	int change_tonality = 0;
	RecordPlayer RC;


	// Introducing
	cout << "Welcome to RecordPlayer programm!" << endl;
	//Sleep(1000);
	cout << endl;
	cout << "We recommend you not to forget to turn on the RecordPlayer" << endl;
	//Sleep(2000);
	cout << "before playing music and changing settings!" << endl;
	//Sleep(2000);
	cout << endl;
	cout << "If you wanna have this device for a long time workable, please" << endl;
	//Sleep(2000);
	cout << "turn off the RecordPlayer, when you finish listening the music!" << endl;
	//Sleep(2000);
	cout << endl;
	cout << "Have a nice time!" << endl;
	//prestartintro();
	//Sleep(1000);
	
	
	while (true)
	{
		if (counter == 0)
		{
			showMenu();
			counter += 1;
		}
		cout << "Choose the option: ";
		option = -1;
		cin >> option;
		cout << endl;

		switch (option)
		{
		case 0:
			RC.turn_on();
			break;
		case 1:
			if (RC.IsTurnedOn() == false)
				break;
			RC.set_bass_mode();
			break;
		case 2:
			if (RC.IsTurnedOn() == false)
				break;
			RC.set_middle_mode();
			break;
		case 3:
			if (RC.IsTurnedOn() == false)
				break;
			RC.set_vocal_mode();
			break;

		case 4:
			if (RC.IsTurnedOn() == false)
				break;
			cout << "Type the number you want to change the volume to" << endl;
			cin >> change_volume;
			if (change_volume > 0)
			{
				RC.volume_up(change_volume);
				break;
			}
			if (change_volume < 0)
			{
				RC.volume_down(change_volume);
				break;
			}
			else
			{
				cout << "You decided not to change the level of volume" << endl;
				break;
			}

		case 5:
			if (RC.IsTurnedOn() == false)
				break;
			cout << "Type the number you want to change the tonality to" << endl;
			cin >> change_tonality;
			if (change_tonality > 0)
			{
				RC.make_more_vocal(change_tonality);
				break;
			}
			if (change_tonality < 0)
			{
				RC.make_more_bass(change_tonality);
				break;
			}
			else
			{
				cout << "You decided not to change the level of tonality" << endl;
				break;
			}
		case 6:
		if (RC.IsTurnedOn() == false)
			break;
		RC.showSettings();
		break;
		case 7:
		if (RC.IsTurnedOn() == false)
			break;
		RC.turn_off();
		breaker = 0;
		break;

		default:
		if (RC.IsTurnedOn() == false)
			break;
		
		cout << "If you forgot the menu, type 1" << endl; // ����������� ����
		cout << "Otherwise, print -1 to return to the main block" << endl;
		cin >> helper; 

		if (helper == -1) // ����������� � ������� ���� ��� ������� ����
			helper = 1;
		if (helper == 1)
			counter = 0;

		while (helper != 1)
		{
			cin >> helper;
			if (helper == 1) 
			{
				counter = 0; 
				helper = 0;
				leaver = 0; // ��������� �������� ���������� ����������, ��� ��� �� ������ ��������� ����.
				break;
			}
			else
			{
				leaver += 1; // ���� leaver ����� 3, �� ��������� (����������) ����������.
				if (leaver != 3)
				{
					cout << "Be careful what you type. Try again" << endl;
					cout << "You have " << (3 - leaver) << " " << "tries." << endl;
					cout << "Otherwise RecordPlayer will turn off" << endl;
				}
				else
				{
					RC.turn_off(); // "���������" ����������
					breaker = 0;
					break;
				}
			}
		}
		if (helper == 1) // ���� ����� ��� ������� ����, �� �������� helper.
		{
			helper = 0;
		}
		
		}
		if (breaker == 0) // ����� �����, ����� ���������.
			break;


	}

	return 0;
}

void showMenu()
{
	cout << "Choose one number to change sound's settings." << endl;
	Sleep(200);
	cout << "0: Turn on the RecordPlayer" << endl;
	Sleep(200);
	cout << "1: Set the bass mode" << endl;
	Sleep(200);
	cout << "2: Set the middle mode" << endl;
	Sleep(200);
	cout << "3: Set the vocal mode" << endl;
	Sleep(200);
	cout << "4: Change the level of volume" << endl;
	Sleep(200);
	cout << "5: Change the tonality" << endl;
	Sleep(200);
	cout << "6: Check the current settings" << endl;
	Sleep(200);
	cout << "7: Turn off the RecordPlayer and exit" << endl;
	Sleep(200);
}

void prestartintro()
{
	for (int i = 0; i < 22; i++)
	{
		cout << "*";
		Sleep(125);
	}
	cout << endl;
	for (int i = 0; i < 22; i++)
	{
		cout << "*";
		Sleep(70);
	}
	cout << endl;
}
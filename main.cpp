#include <iostream>
#include <windows.h>
#include "tree.h"
#include "node.h"
int mainMenu(){
	system("cls");
	int select = 0;
	cout << "===========KIEM TRA TU============" << endl;
	cout << "1. Thao tac voi tu dien."  << endl;
	cout << "2. Thao tac voi van ban."	<< endl;
	cout << "0. Thoat" 					<< endl;
	cout << "Chon: ";
	fflush(stdin);
	cin >> select;
	return select;
}
int dictMenu(){
	system("cls");
	int select = 0;
	cout << "=============THAO TAC VOI TU DIEN==============" 	<< endl;
	cout << "1. Liet ke tu dien"  								<< endl;
	cout << "2. Tra tu"					 					    << endl;
	cout << "3. Them tu" 										<< endl;
	cout << "4. Sua tu" 										<< endl;
	cout << "5. Xoa tu" 										<< endl;
	cout << "6. Luu du lieu tu dien" 							<< endl;
	cout << "0. Tro ve" 										<< endl;
	cout << "Chon: ";
	fflush(stdin);
	cin >> select;
	return select;
}
int docMenu(){
	system("cls");
	int select = 0;
	cout << "=========THAO TAC VOI VAN BAN============" << endl;
	cout << "1. Hien thi van ban" 						<< endl;
	cout << "2. Kiem tra tu"							<< endl;
	cout << "0. Tro ve" 								<< endl;
	cout << "Chon: ";
	fflush(stdin);
	cin >> select;
	return select;
}
void dictAction(int action, AVLTree* dict, char* path){
	string word, mean;
	switch(action){
		case 1:
			dict->show();
			break;
		case 2:
			cout << "Nhap vao tu can tra: ";
			cin >> word;
			dict->search(word);
			break;
		case 3:
			cout << "Nhap tu can them: " << endl;
			cout << "+ Tu: ";			cin >> word;
			cout << "+ Nghia: ";		cin >> mean;
			dict->insert(word, mean); 
			break;
		case 4:
			cout << "Nhap tu can sua: ";	
			cin >> word;
			cout << "Chuc nang chua hoan thanh!" << endl;
			break;
		case 5:
			cout << "Nhap tu can xoa: ";	cin >> word;
			dict->del(word);
			break;
		case 6:
			dict->saveDictData(path);
			cout << "Da luu tu dien!" << endl;
			break;		
	}
}
void docAction(int action, AVLTree* dict, char* path){
	switch(action){
		case 1:
			dict->viewDocument(path);
			break;
		case 2:
			dict->checkDocumentByDict(path);
			break;
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv){
	AVLTree* dict	= new AVLTree();
	char* dict_path = "dictionary.txt";
	char* doc_path  = "document.txt";
	
	dict->loadDictData(dict_path);
	
	int select = 0;
	do
	{
		select = mainMenu();
		switch(select)
		{
			case 1:
				dictAction(dictMenu(), dict, dict_path);
				system("pause > nul");
				break;
			case 2:
				docAction(docMenu(), dict, doc_path);
				system("pause > nul");
				break;
			case 0:
				exit(1);
		}
	}
	while (select != 0);
	
//	cout << "Insert 'art'" << endl;
//	dict->insert("art", "nghe thuat");
//	cout << "Insert 'love'" << endl;
//	dict->insert("love", "tinh yeu");
//	cout << "Insert 'cute'" << endl;
//	dict->insert("cute", "de thuong");
//	cout << "Insert 'cool'" << endl;
//	dict->insert("cool", "ngau");
//	cout << "Insert 'fun'" << endl;
//	dict->insert("fun", "vui");
//	cout << "Insert 'happy'" << endl;
//	dict->insert("happy", "hanh phuc");
//	cout << "Insert 'world'" << endl;
//	dict->insert("world", "the gioi");
//	cout << "Insert 'youth'" << endl;
//	dict->insert("youth", "tuoi tre");
//	dict->del("youth");
//	dict->show();
//	dict->search("love");
//	dict->insert("about", "ve");
//	dict->insert("Past", "qua khu");
//	dict->saveDictData(dict_path);
	
//	dict->show();
//	cout << dict->getSize() << endl;
//	dict->viewDocument(doc_path);
//	dict->checkDocumentByDict(doc_path);
//	system("pause > nul");
	return 0;
}
// test pull request

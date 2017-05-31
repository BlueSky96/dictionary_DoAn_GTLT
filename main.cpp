#include <iostream>
#include <windows.h>
#include "tree.h"
#include "node.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	AVLTree* dict	= new AVLTree();
	char* dict_path = "dict.txt";
	char* doc_path  = "document.txt";
	
	dict->loadDictData(dict_path);
	
	int select = 0;
	do
	{
		cout<<"MENU\n";
		cout<<"Chon: ";
		fflush(stdin);
		cin >> select;
		switch(select)
		{
			case 1:
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:
				break;
			case 0:
				break;
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
//	dict->saveDictData(dict_path);
	
	dict->show();
	cout << dict->getSize() << endl;
//	dict->viewDocument(doc_path);
	dict->checkDocumentByDict(doc_path);
//	system("pause");
	return 0;
}
// test pull request

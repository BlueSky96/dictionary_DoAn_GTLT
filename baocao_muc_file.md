// Lưu dữ liệu từ điển vào file dict.txt
Dùng thư viện fstream để lưu từ và Nghĩa của từ vào file dict.txt theo cấu trúc thứ tự duyệt trái, bắt đầu file là số từ trong từ điển, lần lượt tiếp theo là nghĩa và từ, cách nhau bởi ký tự xuống dòng.
void AVLTree::saveDictData(char* path){
	fstream f;
	f.open(path, ios::out);
	f << this->size << endl;
	preOrderSave(root, f);
	f.close();
}
Trong đó:
+ preOrderSave(root, f): là hàm đệ qui để lưu mỗi node của cây(tương ứng với từng cặp: từ và nghĩa của từ) theo thứ tự duyệt cây từ trái sang phải.

void AVLTree::preOrderSave(Node* r, fstream& f){
	if (r != NULL) {
		preOrderSave(r->left, f);
		saveWord(r, f);
		preOrderSave(r->right, f);
	}
}
+ loadDictData(char* path): là hàm lưu từng cặp từ và nghĩa của từ vào file dict.txt

void AVLTree::saveWord(Node* node, fstream& f){	
	f << node->word << "\n" << node->meaning << endl;
}

==============================================
// Load dữ liệu từ điển từ file dict.txt và lưu từng cặp từ và nghĩa từng node của cây từ điển, cây được tự cân bằng khi gọi phương thức insert(word, mean) để chèn lần lượt từng từ vào cây.
Trong đó:
+ numOfWord: chứa số lượng từ của từ điển.
+ dùng hàm getline() của thư viện fstream để load dữ liệu theo từ dòng theo cặp từ và nghĩa của từ. Gọi hàm seekg(3)
để dịch con trỏ file đến vị trí đến từ đầu tiên cần đọc. Nếu số lượng từ cần đọc chưa đủ, thông báo lỗi và thoát chương trình.

void AVLTree::loadDictData(char* path){
	//this->~AVLTree();
	
	string word, mean;
	fstream f;
	f.open(path, ios::in);
	
	int numOfWord = 0;
	f >> numOfWord;
	f.seekg(3);
	 
	while(!f.eof()){
		getline(f, word);
		getline(f, mean);
		insert(word, mean);
		if(--numOfWord  == 0)	break;
	}
	if(numOfWord != 0){
		cout << "Loi doc file: Khong du so luong tu!" << endl;
		exit(1);
	}
	f.close();	
}
// Hiển thị file doccument.txt.
void AVLTree::viewDocument(char* path){
	fstream f;
	f.open(path, ios::in);
	string doc;
	while(!f.eof()){
		getline(f, doc);
		cout << doc << endl;
	}
	f.close();	
}

//
void AVLTree::checkDocumentByDict(char* path){
	fstream f;
	f.open(path, ios::in);
	string word;
	char c;
	while(!f.eof()){
		word.clear();
		while(isLetter(c)){
			word += c;
			c = f.get();			
		}
		if(!word.empty()){
			if(isExist(word)){
				cout << word << " ";
			}
		}
	}
}

// 
bool AVLTree::isLetter(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

//
bool AVLTree::isExist(string word){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	Node* foo = searchWord(this->root, word);
	return (foo != NULL);
}
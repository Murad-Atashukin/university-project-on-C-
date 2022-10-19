#include "Edition.h"
//Добавление происходит в начало
void Edition::addArtworks(string name) {
	Artworks* tmp = new Artworks;
	tmp->name = name;
	if (head == NULL)
		head = tmp;
	else {
		tmp->nextArtworks = head;
		head = tmp;
	}
	++countArtworks;
}
/*void Edition::deleteArtworks(int index) {
	try {
		if (index < 0 || index >= countArtworks)
			throw exception("Некорректный индекс!"); //создание объекта со строчкой и вывод		на экран			
		Artworks* current = head;
		if (index == 0) { //Удаляем первый элемент
			head = head->nextArtworks;
			delete current;
		}
		else { //Ищем предыдущий			элемент
				for (int i = 0; i < index - 1; ++i)
					current = current->nextArtworks;
			//Здесь current будет указывать на элемент перед элементом, который нажо удалить
			Artworks* tmp = current->nextArtworks; //tmp указывает на элемент,			который надо удалить
			current->nextArtworks = tmp->nextArtworks; //Предыдущий элемент от			удаляемого начинает указывать на элемент после удаляемого
				delete tmp;
			//Удаляем элемент
		}
		--countArtworks;
	}
	catch (exception& ex) { //ссылка на объект класса эксепшн
		cout << ex.what() << endl << endl; //вывод строчки некорректный ввод
	}
}*/
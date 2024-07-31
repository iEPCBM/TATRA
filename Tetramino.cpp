#include "Tetramino.h"

namespace TETRA {
	// Возможные цвета тетраминок
	extern
		int _colors[9][3] = {
			{40,132,70},
			{63,136,143},
			{214,174,1},
			{164,125,144},
			{96,111,40},
			{255,117,20},
			{42,100,120},
			{132,195,190},
			{33,33,33},
	};
	// Возможные конструкции тетраминок
	extern
		std::bitset<16> _bConfigs[7] = {
			std::bitset<16>(
				"1000"
				"1000"
				"1000"
				"1000"
			),
			std::bitset<16>(
				"0000"
				"0011"
				"0010"
				"0010"
			),
			std::bitset<16>(
				"0000"
				"0011"
				"0001"
				"0001"
			),
			std::bitset<16>(
				"0000"
				"0000"
				"0011"
				"0011"
			),
			std::bitset<16>(
				"0000"
				"0000"
				"0011"
				"0110"
			),
			std::bitset<16>(
				"0000"
				"0000"
				"0110"
				"0011"
			),
			std::bitset<16>(
				"0000"
				"0000"
				"0010"
				"0111"
			),
	};
	// Конструктор
	Tetramino::Tetramino() {
		System::Random rand; // Больше рандома, больше энтропии!
		m_pBlock = new std::bitset<16>; // Аллоцируем
		m_pBlockNext = new std::bitset<16>; // Аллоцируем
		*m_pBlock = _bConfigs[rand.Next(0, __TT_END)]; // Указываем контрукцию
		*m_pBlockNext = _bConfigs[rand.Next(0, __TT_END)]; // Указываем контрукцию следующей тетраминки
		
		int ci = rand.Next(0, 9); 
		m_color = Color::FromArgb(_colors[ci][0], _colors[ci][1], _colors[ci][2]); // Указываем цвет
		m_posX = 6; // Спавн-поинт
		m_posY = 0;
	}
	// Метод рендера
	void Tetramino::render(List<List<PictureBox^>^>^ cnv) {
		try {
			// Проходим по всем возможным блокам Тетраминки
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if ((*m_pBlock)[i * 4 + j]) { // Если стоит блок,
						auto r = cnv[j + m_posX];
						r[i + m_posY]->BackColor = m_color; // Рисуем его
					}
				}
			}
		}
		catch(...) {

		}
	}
	// Метод рендера следующей тетраминки в мини-экране
	void Tetramino::renderNext(List<List<PictureBox^>^>^ cnv) {
		try {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					auto r = cnv[j];
					if ((*m_pBlockNext)[i * 4 + j]) { // Есть блок? Красим в красный
						r[i]->BackColor = System::Drawing::Color::Red;
					}
					else {
						r[i]->BackColor = System::Drawing::Color::AliceBlue;
					}
				}
			}
		}
		catch (...) {
			// Чтоб прога не ныла, когда тетраминка выходит за пределы экрана.
			// Раньше надо было, Сейчас - не особо. try-catch здесь можно убрать.
		}
	}
	// Сброс текущей тетраминки (DRY? Не, не слышал!) См. конструктор
	void Tetramino::reset() {
		System::Random rand;
		m_pBlock = new std::bitset<16>;
		*m_pBlock = *m_pBlockNext;
		*m_pBlockNext = _bConfigs[rand.Next(0, __TT_END)];
		m_isLocked = false;
		int ci = rand.Next(0, 9);
		m_color = Color::FromArgb(_colors[ci][0], _colors[ci][1], _colors[ci][2]);
		m_posX = 6;
		m_posY = 0;
	}
	// Обновить игровое поле с статическими блоками
	Playground^ Tetramino::updatePg(Playground^ pg0) {
		Playground^ pg = ClonePg(pg0);
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 16; j++) {
				if (i >= m_posY && i <= m_posY + 3
					&& j >= m_posX && j <= m_posX + 3) {
					auto r = pg[i]; 
					if ((*m_pBlock)[(i - m_posY) * 4 + (j - m_posX)]) {
						r[j] = (*m_pBlock)[(i - m_posY) * 4 + (j - m_posX)]?m_color:Color::Black;
						// Черный - свободный блок, иначе - занятый
					}
				}
			}
		}
		return pg;
	}
	// Копируем игровое поле. Для проверки допустимости действия
	Playground^ Tetramino::ClonePg(Playground^ pg0) {
		Playground^ pg = gcnew Playground;
		for each (auto a in pg0) {
			List<Color>^ l = gcnew List<Color>;
			for each (auto m in a) {
				l->Add(m);
			}
			pg->Add(l);
		}
		return pg;
	}

	// Шаг Тетраминки
	void Tetramino::step(Playground^ pg0) {
		Playground^ pg = ClonePg(pg0);
		m_posY++;
		bool a = !isValidMove(pg);
		bool b = !isValidMoveG();
		if (a || b) { // Если шаг недопустим
			m_posY--; // Откатываем назад
			m_isLocked = true; // Блокируем тетраминку
		}
	}
	
	// Вращение тетраминки. Я хз, как объяснить. Магия Афинных преобразований
	void Tetramino::rotate(Playground^pg0) {
		Playground^ pg = ClonePg(pg0);
		std::bitset<16> b(0x0000L);
		std::bitset<16> t(0x0000L);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				b[j * 4 + 3 - i] = (*m_pBlock)[i * 4 + j]; // Афинное преобразование. Вращение на 90 градусов.
				// Ах да, свежие тетраминки имеют одномерную структуру
			}
		}
		t = (*m_pBlock);
		(*m_pBlock) = b;
		if (!isValidMove(pg) || !isValidMoveG()) { // Проверяем допустимость вращения
			(*m_pBlock) = t; // Если вращение оказалось недопустимым, откатываем преобразование назад
		}

	}
	 // Мув
	void Tetramino::move(bool left, Playground^ pg0) {
		Playground^ pg = ClonePg(pg0);
		if (left) { // Левый мув
			m_posX--;
			if (!isValidMove(pg) || !isValidMoveG()) { // Если действие недопустимо
				m_posX++; // Откатываем
			}
		}
		else { // Правый мув
			m_posX++;
			if (!isValidMove(pg) || !isValidMoveG()) { // Если действие недопустимо
				m_posX--; // Откатываем
			}
		}
	}
	// Если тетраминка заблокирована
	bool Tetramino::isLocked() {
		return m_isLocked;
	}
	// Добустимо ли действие относительно рамки
	bool Tetramino::isValidMoveG() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {

				if ((*m_pBlock)[i * 4 + j]) {
					if ((m_posX + j < 0 || m_posX + j>15)
						&& (m_posY + i < 0 || m_posY + i > 23))
						return false;

				}
			}
		}
		return true;
	}
	// Допустимо ли действие относительно старых(статичных) тетраминок
	bool Tetramino::isValidMove(Playground^ pg0) {
		Playground^ pg = gcnew Playground(pg0);
		int checksum_A = 4; // Количество блоков у активной тетраминки
		for each (auto a in pg) { // Считаем количество блоков статичных тетраминок, а также активной
			for each (auto m in a) {// Лиза, ты очень симпатичная!
				checksum_A += m != Color::Black ? 1 : 0; // А еще ты милашка!
			}
		}

		// Накладываем на копию игрового поля активную тетраминку
		// Overlay
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 16; j++) {
				if (i >= m_posY && i <= m_posY + 3
					&& j >= m_posX && j <= m_posX + 3) {
					auto r = pg[i];
					if ((*m_pBlock)[(i - m_posY) * 4 + (j - m_posX)])
						r[j] = (*m_pBlock)[(i - m_posY) * 4 + (j - m_posX)]?m_color:Color::Black;
				}
			}
		}

		// Считаем количество блоков тетраминок на получившимся поле
		int checksum_B = 0;
		for each (auto a in pg) {
			for each (auto m in a) {
				checksum_B += m != Color::Black ? 1 : 0;
			}
		}
		// Если суммы одинаковые, то все ок. Вспомни теорию множеств
		return checksum_B == checksum_A;
	}
};
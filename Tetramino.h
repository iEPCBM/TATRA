#pragma once
#include <bitset>
#include "Playground.h"
namespace TETRA {

	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	// Энамка для дебага и облегчения написания кода генерации тетраминок
	enum TetraminoType_t {
		TT_I = 0,
		TT_J,
		TT_L,
		TT_O,
		TT_S,
		TT_Z,
		TT_T,
		__TT_END
	};
	// Класс Тетраминки в активе. Подробности жизни Тетраминки в .cpp файле
	public ref class Tetramino
	{
	public:
		explicit
			Tetramino();
		
		~Tetramino() {
			if (m_pBlock)
				delete m_pBlock;
			if (m_pBlockNext)
				delete m_pBlockNext;
		};

		void render(List<List<PictureBox^>^>^ cnv);
		void renderNext(List<List<PictureBox^>^>^ cnv);
		void rotate(Playground^ pg0);
		void step(Playground^ pg);
		void __fastcall move(bool left, Playground^ pg); // Не, ну только здесь это может быть уместно (__fastcall)
		Playground^ updatePg(Playground^ pg);

		bool isLocked();
		void reset();
		Playground ^ClonePg(Playground^ pg0);
		bool isValidMoveG();
		bool isValidMove(Playground^ pg);
	private:
		int m_posX = 0, m_posY = 0; // Позиция блока
		System::Drawing::Color m_color; // Цвет текущего блока
		std::bitset<16>* m_pBlock = nullptr; // Указатель на констуркуцию текущего блока
		std::bitset<16>* m_pBlockNext = nullptr; // Указатель на констуркуцию следующего блока
		bool m_isLocked = false; // Заблочена ли Тетраминка
		int m_cnvW = 16; // Длина экрана
		int m_cnvH = 24; // Высота экрана (DRY? Не, это не для меня)
	};
}

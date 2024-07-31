#pragma once
#include <bitset>
#include "Playground.h"
namespace TETRA {

	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	// ������ ��� ������ � ���������� ��������� ���� ��������� ����������
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
	// ����� ���������� � ������. ����������� ����� ���������� � .cpp �����
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
		void __fastcall move(bool left, Playground^ pg); // ��, �� ������ ����� ��� ����� ���� ������� (__fastcall)
		Playground^ updatePg(Playground^ pg);

		bool isLocked();
		void reset();
		Playground ^ClonePg(Playground^ pg0);
		bool isValidMoveG();
		bool isValidMove(Playground^ pg);
	private:
		int m_posX = 0, m_posY = 0; // ������� �����
		System::Drawing::Color m_color; // ���� �������� �����
		std::bitset<16>* m_pBlock = nullptr; // ��������� �� ������������ �������� �����
		std::bitset<16>* m_pBlockNext = nullptr; // ��������� �� ������������ ���������� �����
		bool m_isLocked = false; // ��������� �� ����������
		int m_cnvW = 16; // ����� ������
		int m_cnvH = 24; // ������ ������ (DRY? ��, ��� �� ��� ����)
	};
}

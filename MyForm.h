#pragma once

#include "Tetramino.h"

#include "Playground.h"

#define INTERVAL_BASIC 250
#define INTERVAL_SPEEDUP 50

namespace TETRA {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;
    using namespace System::Media;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form {
    private: Tetramino m_curTetra;
           bool m_canPressKeyW = true;
           bool m_canPressKeyA = true;
           bool m_canPressKeyD = true;
           int m_score = 0;
           Playground^ m_playground;
           SoundPlayer^ musicPlayer;

    public:
        // Конструктор
        MyForm(void) {
            musicPlayer = gcnew SoundPlayer(".\\music.wav");

            m_playground = gcnew Playground;
            // Заполняем m_playground
            for (int i = 0; i < 24; i++) {
                List < System::Drawing::Color >^ r = gcnew List < System::Drawing::Color >;
                for (int j = 0; j < 16; j++) {
                    r->Add(System::Drawing::Color::Black);
                }
                m_playground->Add(r);
            }
            lPixels = gcnew List < List < PictureBox^ >^ >;
            lPixelsNext = gcnew List < List < PictureBox^ >^ >;
            InitializeComponent();

            timerTick->Interval = INTERVAL_BASIC;
        }

        // Сброс состояния
        void resetState() {
            m_score = 0;
            lbRows->Text = m_score.ToString();
            m_curTetra.reset();
            for (int i = 0; i < m_playground->Count; i++) {
                for (int j = 0; j < m_playground[i]->Count; j++) {
                    auto r = m_playground[i];
                    r[j] = Color::Black; // Заполняем деволтными цветами
                }
            }
            for (int i = 0; i < lPixelsNext->Count; i++) {
                for (int j = 0; j < lPixelsNext[i]->Count; j++) {
                    auto r = lPixelsNext[i];
                    r[j]->BackColor = Color::AliceBlue;
                }
            }
            m_curTetra.renderNext(lPixelsNext);
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm() {
            if (components) {
                delete components;
            }
        }
    private: System::Windows::Forms::TableLayoutPanel^ tlpPlayground;
    protected:

    protected: private: System::Windows::Forms::Button^ btStart;
    private: System::Windows::Forms::TableLayoutPanel^ tlpNextBlock;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ lbRows;

    private: List < List < PictureBox^ >^ >^ lPixels;
    private: List < List < PictureBox^ >^ >^ lPixelsNext;
    private: System::Windows::Forms::Timer^ timerTick; // Таймер
    private: System::ComponentModel::IContainer^ components;

    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        /// 
        /// Осторожно! В region ниже не смотреть! Там еще вырвиглазней, чем здесь...

#pragma region Windows Form Designer generated code
/// <summary>
/// Требуемый метод для поддержки конструктора — не изменяйте 
/// содержимое этого метода с помощью редактора кода.
/// </summary>
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->tlpPlayground = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->btStart = (gcnew System::Windows::Forms::Button());
            this->tlpNextBlock = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->lbRows = (gcnew System::Windows::Forms::Label());
            this->timerTick = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // tlpPlayground
            // 
            this->tlpPlayground->AutoSize = true;
            this->tlpPlayground->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tlpPlayground->ColumnCount = 16;
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpPlayground->Location = System::Drawing::Point(12, 12);
            this->tlpPlayground->Name = L"tlpPlayground";
            this->tlpPlayground->RowCount = 24;
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpPlayground->Size = System::Drawing::Size(320, 480);
            this->tlpPlayground->TabIndex = 0;
            // 
            // btStart
            // 
            this->btStart->Location = System::Drawing::Point(12, 500);
            this->btStart->Name = L"btStart";
            this->btStart->Size = System::Drawing::Size(321, 23);
            this->btStart->TabIndex = 1;
            this->btStart->Text = L"Стартуем";
            this->btStart->UseVisualStyleBackColor = true;
            this->btStart->Click += gcnew System::EventHandler(this, &MyForm::btStart_Click);
            this->btStart->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
            this->btStart->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
            // 
            // tlpNextBlock
            // 
            this->tlpNextBlock->AutoSize = true;
            this->tlpNextBlock->ColumnCount = 4;
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                22)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->tlpNextBlock->Location = System::Drawing::Point(360, 182);
            this->tlpNextBlock->Name = L"tlpNextBlock";
            this->tlpNextBlock->RowCount = 4;
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tlpNextBlock->Size = System::Drawing::Size(82, 80);
            this->tlpNextBlock->TabIndex = 2;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(357, 162);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(136, 17);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Следующий символ";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(357, 12);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(197, 17);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Укомплектовано рядов (УР):";
            // 
            // lbRows
            // 
            this->lbRows->AutoSize = true;
            this->lbRows->Location = System::Drawing::Point(357, 29);
            this->lbRows->Name = L"lbRows";
            this->lbRows->Size = System::Drawing::Size(0, 17);
            this->lbRows->TabIndex = 5;
            // 
            // timerTick
            // 
            this->timerTick->Interval = 150;
            this->timerTick->Tick += gcnew System::EventHandler(this, &MyForm::timerTick_Tick);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(570, 535);
            this->Controls->Add(this->lbRows);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->tlpNextBlock);
            this->Controls->Add(this->btStart);
            this->Controls->Add(this->tlpPlayground);
            this->Name = L"MyForm";
            this->Text = L"Татра-645";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
            this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        // Когда окно загружено
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        lbRows->Text = m_score.ToString();
        for (int i = 0; i < tlpPlayground->ColumnCount; i++) {
            List < PictureBox^ >^ row = gcnew List < PictureBox^ >;
            for (int j = 0; j < tlpPlayground->RowCount; j++) {
                PictureBox^ pb = gcnew PictureBox; // Заполняем все экраны PictureBox ами
                pb->Margin.All = 1;
                pb->Padding.All = 1;
                pb->Dock = DockStyle::Fill;
                pb->BackColor = System::Drawing::Color::LightGray;
                row->Add(pb);
                tlpPlayground->Controls->Add(pb, i, j);
            }
            lPixels->Add(row);
        }

        for (int i = 0; i < tlpNextBlock->ColumnCount; i++) {
            List < PictureBox^ >^ row = gcnew List < PictureBox^ >;
            for (int j = 0; j < tlpNextBlock->RowCount; j++) {
                PictureBox^ pb = gcnew PictureBox; // Заполняем все экраны PictureBox ами
                pb->Margin.All = 1;
                pb->Padding.All = 1;
                pb->Dock = DockStyle::Fill;
                pb->BackColor = System::Drawing::Color::LightGray;
                row->Add(pb);
                tlpNextBlock->Controls->Add(pb, i, j);
            }
            lPixelsNext->Add(row);
        }

        //m_curTetra.render(lPixels);
    }
    private: System::Void timerTick_Tick(System::Object^ sender, System::EventArgs^ e) {
        m_canPressKeyW = m_canPressKeyA = m_canPressKeyD = true;

        clearCanvas(); // Очистка экрана
        m_curTetra.step(m_playground); // Шаг тетрамины
        if (m_curTetra.isLocked()) { // Если тетрамина заблокирована,
            m_playground = m_curTetra.updatePg(m_playground); // Добавляем ее в статичные блоки
            m_curTetra.reset(); // Готовим следующий тетрамино
            m_score += clearFilledRows(); // Проверяем и удаляем заполненные ряды
            lbRows->Text = m_score.ToString(); // Обновляем очки
            m_curTetra.renderNext(lPixelsNext); // Рендерим следующий блок в мини-экране
        }
        m_curTetra.render(lPixels); // Рендерим тетрамину на экране
        for (int i = 0; i < 24; i++) { // Рендерим статичные элементы
            for (int j = 0; j < 16; j++) {
                auto r = m_playground[i];
                auto a = lPixels[j];
                if (r[j] != Color::Black) {
                    a[i]->BackColor = r[j];
                }
            }
        }
        if (checkGameOver()) { // Если игра окончена,
            safe_cast <Timer^> (sender)->Stop(); // Останавливаем таймер
            musicPlayer->Stop(); // Вырубаем музочик
            MessageBox::Show("Игра окончена");
            btStart->Text = "Стартуем";
        }
    }

    private:
        // Очистка экрана
        void clearCanvas() {
            for (int i = 0; i < lPixels->Count; i++) {
                auto a = lPixels[i];
                for (int j = 0; j < a->Count; j++) {
                    a[j]->BackColor = System::Drawing::Color::LightGray; // Заполняем ячейки дефолтным цветом
                }
            }
        }
    private:
        // При нажатии на клавишу
        System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            // Почему decltype()? Потому, что мне лень искать, что за тип там. Все-равно compile-time выражение.
            if (e->KeyCode == decltype(e->KeyCode)::A && m_canPressKeyA) {
                m_canPressKeyA = false; // Ограничитель передвижения
                m_curTetra.move(true, m_playground); // Делаем мув
            }
            if (e->KeyCode == decltype(e->KeyCode)::D && m_canPressKeyD) {
                m_canPressKeyD = false; // Ограничитель передвижения
                m_curTetra.move(false, m_playground); // Делаем мув
            }
            if (e->KeyCode == decltype(e->KeyCode)::W && m_canPressKeyW) {
                m_canPressKeyW = false; // Ограничитель передвижения
                m_curTetra.rotate(m_playground); // Ротацируемся!
            }
            if (e->KeyCode == decltype(e->KeyCode)::S) {
                timerTick->Interval = INTERVAL_SPEEDUP; // Ускорение
            }
        }
    private:
        // При опускании клавиши
        System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            // Почему decltype()? Потому, что мне лень искать, что за тип там. Все-равно compile-time выражение.
            if (e->KeyCode == decltype(e->KeyCode)::S) {
                timerTick->Interval = INTERVAL_BASIC; // Замедляемся
            }
            if (e->KeyCode == decltype(e->KeyCode)::A) {
                m_canPressKeyA = true;
            }
            if (e->KeyCode == decltype(e->KeyCode)::D) {
                m_canPressKeyD = true;
            }
            if (e->KeyCode == decltype(e->KeyCode)::W) {
                m_canPressKeyW = true;
            }
        }

    private:
        // Удаление заполненных строк    
        int clearFilledRows() {
            // Счетчик = 0
            int counter = 0;
            // Пролетаем по всем строкам игрового поля
            for (int i = 0; i < m_playground->Count; i++) {
                // r - текущая строка в игровом полк
                auto r = m_playground[i];
                // переменая, отвечающая на вопрос "Заполнена ли строка?". Устанавливаем изначальное значение как ИСТИНА
                bool isFilled = true;
                // Пролетаем по всем клеткам строки (c - клетка строки r)
                for each (auto c in r) {
                    // Возможно, вы проходили логику на ДГМ. Но это не точно.
                    // Точно то, что ты милашка ❤
                    // Новое значение переменной isFilled равна isFilled =ЛОГИЧЕСКАЯ И= (текущая клетка НЕ черная?)
                    isFilled &= c != Color::Black;
                }
                // Если после всех опираций isFilled по-прежнему равна ИСТИНЕ (строка заполнена)
                if (isFilled) {
                    counter++; // счетчик крутится - деньги мутятся! Или Счетчик + 1
                    m_playground->RemoveAt(i); // Удаляем текущую строку из игрового поля
                    // Почему decltype()? Потому, что мне лень писать тип целиком. Все-равно compile-time выражение.
                    decltype(r) f = gcnew List < Color >; // Создаем новую строку
                    for (int i = 0; i < 16; i++) { 
                        f->Add(Color::Black); // Заполняем новую строку черными клетками (т. е. свободными клетками)
                    }
                    m_playground->Insert(0, f); // Вставляем получившуюся пустую строку сверху игрового поля
                }
            }
            // Накрученный счетчик возвращаем. Его значение пойдет в счет очков игрока.
            return counter;
        }
        // Проверяем окончание игры
        bool checkGameOver() {
            auto r = m_playground[3]; // Строка-потолок.
            // Статичные блоки на этой строке будут вызывать окончание игры
            for each (auto c in r) {
                if (c != Color::Black)
                    return true;
            }
            return false;
        }
    private:
        // При нажатии на кнопку
        System::Void btStart_Click(System::Object^ sender, System::EventArgs^ e) {
            // Если игра выключена
            if (!timerTick->Enabled) {
                resetState(); // Сбрасываем состояние и запускаем игру
                timerTick->Start();
                safe_cast <Button^> (sender)->Text = "Я устал"; // Меняем текст у кнопки, вызвавшей событие
                musicPlayer->PlayLooping(); // Врубаем музочик
            }
            else {
                timerTick->Stop(); // Иначе - останавливаем игру
                safe_cast <Button^> (sender)->Text = "Стартуем"; // Меняем текст у кнопки, вызвавшей событие
                musicPlayer->Stop(); // Вырубаем музочик
            }
        }
    };
}
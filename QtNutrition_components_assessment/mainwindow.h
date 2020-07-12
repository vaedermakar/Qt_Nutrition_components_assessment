#pragma once

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define AMI 9      // количество аминокислот
#define LIP_PROP 5 // липидные хар-ки (аналог аминокислот)
#define MAX_COMP 5 // максимальное количество компонентов

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    size_t comp_num; // кол-во компонентов

    const double fao_voz2007[AMI] = {3.9, 1.5, 3.0, 5.9, 4.5, 2.2, 2.3, 0.6, 3.8};
    const double fao_voz2008[MAX_COMP] = {33.33, 33.33, 33.33, 6.67, 26.67};

    /*БЕЛКИ*/
    double protein[MAX_COMP] = {0.0}; // кол-во белка на 100г каждого компонента
    double comp[MAX_COMP][AMI] = {{0.0}}; // для аминокислот

    /*ЛИПИДЫ*/
    double lipids[MAX_COMP] = {0.0};
    double ultimate[MAX_COMP][LIP_PROP] = {{0.0}};

    /*ДЛЯ РЕЗУЛЬТАТОВ ВЫЧИСЛЕНИЙ*/

    /*БЕЛКИ*/
    double akp[AMI] = {0.0};
    double aminoacidskor[AMI] = {0.0};
    double koef_ration[AMI] = {0.0};
    double fatty_acid_per_100g[AMI] = {0.0};
    double prop[MAX_COMP] = {0.0}; // для пропорций, если компонентов > 1
    double recount[MAX_COMP][AMI] = {{0.0}}; // для пересчёта аминокилот
    /*коэффициент разбалансированности, биологическая ценность,
        коэффициент рациональности аминокислотного состава,
        индекс сбалансированности, показатель сопоставимой избыточности и
        коэффициент сбалансированности всей белковой составляющей(вычисляются 1 раз в конце)*/
    double kras = 0.0;
    double biological_value = 0.0; // bc
    double amino_acid_comp_ratio_coef = 0.0; // r
    double comparable_redundancy_ratio = 0.0; // g
    double balance_index = 0.0; // s
    double k_general = 0.0;
    int i; // счётчик, номер строки с аминокислотой

    /*ЛИПИДЫ*/
    double recount_lip[MAX_COMP][LIP_PROP] = {{0.0}};
    double ratio_calc[LIP_PROP] = {0.0};
    double lip_balance_ratio[LIP_PROP] = {0.0};
    double result1 = 0.0;
    double result2 = 0.0;

    QList<QDoubleSpinBox*> getColumnOfCompSpinboxes(int column);
    QList<QLabel*> listCompLabels;

    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    void setTabOrder();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_spinBoxComp_valueChanged(int value);
};

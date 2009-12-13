#include <QtTest/QtTest>

class BranchAndBoundTest : public QObject
{
Q_OBJECT private slots:
void toUpper();
};

void
BranchAndBoundTest::toUpper()
{
  QString str = "Hello";
  QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN( BranchAndBoundTest)
#include "BranchAndBoundTest.moc"

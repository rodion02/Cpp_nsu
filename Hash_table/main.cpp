#include <gtest.h>
#include "Hashtable.h"


using namespace std;


class GoogleTest : public::testing::Test
{
protected:
    HashTable table1, table2, table3;

    void SetUp() override
    {
        table1.insert("James", { 21, 70 });
        table1.insert("Lara", { 21, 55 });
        table1.insert("Lily", { 20, 73 });
        table1.insert("Jhon", { 19, 67 });
        table1.insert("Timothy", { 22, 80 });
        table1.insert("Tom", { 18, 65 });
        table1.insert("Anne", { 20, 60 });
        table1.insert("Barry", { 21, 65 });

        table2.insert("Paul", { 19, 68 });
        table2.insert("Edgar", { 23, 91 });
        table2.insert("Emily", { 20, 74 });
        table2.insert("William", { 21, 84 });
        table2.insert("Ringo", { 22, 68 });
        table2.insert("Staphany", { 20, 50 });
        table2.insert("Anastasia", { 19, 68 });
        table2.insert("Harry", { 21, 64 });

    }

    void TearDown() override {}
};

TEST_F(GoogleTest, Constructor)
{
    HashTable table4 = HashTable(table2);
    HashTable table5 (move(table2));
    ASSERT_EQ(table4, table5);
}

TEST_F(GoogleTest, TestCompareTables)
{
    ASSERT_TRUE(table2.size() != 10);
    ASSERT_EQ(table1.size(), 8);
    ASSERT_FALSE(table1 == table2);
}

TEST_F(GoogleTest, SwapAndContains)
{
    table1.swap(table2);

    ASSERT_TRUE(table1.contains("Paul"));
    ASSERT_TRUE(table1.contains("Edgar"));
    ASSERT_TRUE(table1.contains("Emily"));
    ASSERT_FALSE(table1.contains("James"));
    ASSERT_FALSE(table1.contains("Lara"));
    ASSERT_FALSE(table1.contains("Lily"));

    ASSERT_TRUE(table2.contains("Jhon"));
    ASSERT_FALSE(table2.contains("Edgar"));

}


TEST_F(GoogleTest, TestErase)
{
    ASSERT_FALSE(table1.erase("Rose"));

    ASSERT_EQ(table1.size(), 8);
    ASSERT_TRUE(table1.erase("Tom"));
    ASSERT_EQ(table1.size(), 7);
    table1.insert("Tom", { 18, 65 });
}

TEST_F(GoogleTest, TestInsert)
{
    ASSERT_TRUE(table1.insert("Emily", { 21, 70 }));
    ASSERT_FALSE(table1.insert("Emily", { 23, 52 }));
    table1.erase("Emily");
}

TEST_F(GoogleTest, TestAt)
{
    Value test = { 18, 65 };
    ASSERT_EQ(table1.at("Tom").age, test.age);
//    value = { 21, 70 };
//    ASSERT_EQ(table1.at("Timmy"), value);
//    ASSERT_THROW(table1.at("Timmy"), "Student doesnt exist");
//
}

TEST_F(GoogleTest, TestSize)
{
    ASSERT_EQ(table1.size(), 8);
    table1.erase("Lily");
    ASSERT_EQ(table1.size(), 7);
}




TEST_F(GoogleTest, TestClearAndEmpty)
{
    ASSERT_FALSE(table1.empty());
    table1.clear();
    ASSERT_TRUE(table1.empty());
}


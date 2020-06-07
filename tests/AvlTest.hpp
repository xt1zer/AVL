#pragma once
#include "AVL.hpp"
#include <cppunit/extensions/HelperMacros.h>

class AvlTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(AvlTest);

    CPPUNIT_TEST(InitTree);
    CPPUNIT_TEST(FillTree);
    CPPUNIT_TEST(Traversals);
    CPPUNIT_TEST(TreeHeight);
    CPPUNIT_TEST(TreeBalance);
    CPPUNIT_TEST(ClearTree);
    CPPUNIT_TEST(AddAndDelete);

    CPPUNIT_TEST_SUITE_END();

public:
    AvlTest();
    virtual ~AvlTest();
    void setUp();
    void tearDown();

private:
    AVL* tree;
    void InitTree();
    void FillTree();
    void Traversals();
    void TreeHeight();
    void TreeBalance();
    void ClearTree();
    void AddAndDelete();
};

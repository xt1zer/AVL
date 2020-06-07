#include "AvlTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AvlTest);

AvlTest::AvlTest() {
    tree = new AVL;
}

AvlTest::~AvlTest() {
    delete tree;
}

void AvlTest::setUp() {
}

void AvlTest::tearDown() {
}

void AvlTest::InitTree() {
    CPPUNIT_ASSERT_MESSAGE("Tree isn't initialised correctly", tree->isEmpty());
}

void AvlTest::FillTree() {
    tree->add(10);
    tree->add(7);
    tree->add(21);
    CPPUNIT_ASSERT(tree->find(21));
    tree->add(5);
    tree->add(6);
    tree->add(9);
    tree->add(2);
    tree->add(2);
    CPPUNIT_ASSERT(!tree->find(1));
}

void AvlTest::Traversals() {
    CPPUNIT_ASSERT_EQUAL(std::string("7 5 2 6 10 9 21 "), tree->preOrderTraversal());
    CPPUNIT_ASSERT_EQUAL(std::string("2 5 6 7 9 10 21 "), tree->inOrderTraversal());
    CPPUNIT_ASSERT_EQUAL(std::string("2 6 5 9 21 10 7 "), tree->postOrderTraversal());
    CPPUNIT_ASSERT_EQUAL(std::string("7 5 10 2 6 9 21 "), tree->breadthTraversal());
}

void AvlTest::TreeHeight() {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong height value", 2, tree->getHeight());
}

void AvlTest::TreeBalance() {
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Balance isn't calculated correctly", 0, tree->getBalance());
}

void AvlTest::ClearTree() {
    tree->clear();
    CPPUNIT_ASSERT_MESSAGE("Tree wasn't cleared correctly", tree->isEmpty());
}

void AvlTest::AddAndDelete() {
    tree->add(5);
    tree->remove(5);

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong removed value", 5, 5);
    CPPUNIT_ASSERT_MESSAGE("Found unexpected value", !tree->remove(1));
}

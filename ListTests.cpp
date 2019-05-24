#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sem4_lab1/ListClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(Tests_with_int)
{
public:
	ListClass<int> * testList;

	TEST_METHOD_INITIALIZE(SetUp)
	{
		testList = new ListClass<int>();
	}

	TEST_METHOD_CLEANUP(CleanUp)
	{
		delete testList;
	}

	TEST_METHOD(push_back_first_node)
	{
		testList->push_back(10);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == (size_t)1 && testList->at(0) == 10);
	}

	TEST_METHOD(push_back_multiple_times)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == (size_t)3 && testList->at(0) == 10 && testList->at(1) == 11 && testList->at(2) == 12);
	}



	TEST_METHOD(push_front_first_node)
	{
		testList->push_front(10);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == (size_t)1 && testList->at(0) == 10);
	}

	TEST_METHOD(push_front_multiple_times)
	{
		testList->push_front(12);
		testList->push_front(11);
		testList->push_front(10);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == (size_t)3 && testList->at(0) == 10 && testList->at(1) == 11 && testList->at(2) == 12);
	}

	TEST_METHOD(pop_back_one_node)
	{
		testList->push_back(10);
		testList->pop_back();
		Assert::IsTrue(testList->isEmpty() && testList->get_size() == 0);
	}

	TEST_METHOD(pop_back_multiple_times)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);
		testList->push_back(13);
		testList->push_back(14);

		testList->pop_back();
		testList->pop_back();
		testList->pop_back();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 10 && testList->at(1) == 11);
	}

	TEST_METHOD(pop_front_one_node)
	{
		testList->push_back(10);
		testList->pop_front();
		Assert::IsTrue(testList->isEmpty() && testList->get_size() == 0);
	}

	TEST_METHOD(pop_front_multiple_times)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);
		testList->push_back(13);
		testList->push_back(14);

		testList->pop_front();
		testList->pop_front();
		testList->pop_front();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 13 && testList->at(1) == 14);
	}

	TEST_METHOD(insert_head)
	{
		testList->push_back(10);
		testList->push_back(11);
		
		testList->insert(0,9);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 3 && testList->at(0) == 9 && testList->at(1) == 10 && testList->at(2) == 11);
	}

	TEST_METHOD(insert_in_the_middle)
	{
		testList->push_back(10);
		testList->push_back(12);

		testList->insert(1, 11);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 3 && testList->at(0) == 10 && testList->at(1) == 11 && testList->at(2) == 12);
	}

	TEST_METHOD(insert_tail)
	{
		testList->push_back(10);
		testList->push_back(11);

		testList->insert(2, 12);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 3 && testList->at(0) == 10 && testList->at(1) == 11 && testList->at(2) == 12);
	}

	TEST_METHOD(at)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		Assert::IsTrue(testList->at(0) == 10 && testList->at(1) == 11 && testList->at(2) == 12);
	}

	TEST_METHOD(remove_head)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		testList->remove(0);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 11 && testList->at(1) == 12);
	}

	TEST_METHOD(remove_tail)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		testList->remove(2);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 10 && testList->at(1) == 11);
	}

	TEST_METHOD(remove_in_the_middle)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		testList->remove(1);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 10 && testList->at(1) == 12);
	}

	TEST_METHOD(get_size)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		Assert::IsTrue(testList->get_size() == 3);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		testList->clear();
		Assert::IsTrue(testList->isEmpty());
	}

	TEST_METHOD(set)
	{
		testList->push_back(10);
		testList->push_back(11);
		testList->push_back(12);

		testList->set(1, 110);
		Assert::IsTrue(testList->at(0) == 10 && testList->at(1) == 110 && testList->at(2) == 12);
	}
};


TEST_CLASS(Tests_with_char)
{
public:
	ListClass<char> * testList;

	TEST_METHOD_INITIALIZE(SetUp)
	{
		testList = new ListClass<char>();
	}

	TEST_METHOD_CLEANUP(CleanUp)
	{
		delete testList;
	}

	TEST_METHOD(push_back)
	{
		testList->push_back('a');
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == 1 && testList->at(0) == 'a');
	}

	TEST_METHOD(push_front)
	{
		testList->push_front('b');
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == 1 && testList->at(0) == 'b');
	}

	TEST_METHOD(pop_back)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		testList->pop_back();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 'a' && testList->at(1) == 'b');
	}

	TEST_METHOD(pop_front)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		testList->pop_front();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 'b' && testList->at(1) == 'c');
	}

	TEST_METHOD(insert)
	{
		testList->push_back('a');
		testList->push_back('c');

		testList->insert(1, 'b');
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 3 && testList->at(0) == 'a' && testList->at(1) == 'b' && testList->at(2) == 'c');
	}

	TEST_METHOD(at)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		Assert::IsTrue(testList->at(0) == 'a' && testList->at(1) == 'b' && testList->at(2) == 'c');
	}

	TEST_METHOD(remove)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		testList->remove(1);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == 'a' && testList->at(1) == 'c');
	}

	TEST_METHOD(get_size)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		Assert::IsTrue(testList->get_size() == 3);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		testList->clear();
		Assert::IsTrue(testList->isEmpty());
	}

	TEST_METHOD(set)
	{
		testList->push_back('a');
		testList->push_back('b');
		testList->push_back('c');

		testList->set(1, 'd');
		Assert::IsTrue(testList->at(0) == 'a' && testList->at(1) == 'd' && testList->at(2) == 'c');
	}
};








TEST_CLASS(Tests_with_class)
{
public:
	class testClass //simple class for template tests 
	{
	public:
		int a = 1;
		int b = 2;

		const bool operator== (const testClass& testClass1) 
		{
			return (a == testClass1.a && b == testClass1.b);
		}
	};


	ListClass<testClass> * testList;
	testClass testClass1;
	testClass testClass2;
	testClass testClass3;

	TEST_METHOD_INITIALIZE(SetUp)
	{
		testList = new ListClass<testClass>();
		testClass2.a = 3;
		testClass2.b = 4;
		testClass3.a = 5;
		testClass2.b = 6;
	}

	TEST_METHOD_CLEANUP(CleanUp)
	{
		delete testList;
	}

	TEST_METHOD(push_back)
	{
		testList->push_back(testClass1);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == 1 && testList->at(0) == testClass1);
	}

	TEST_METHOD(push_front)
	{
		testList->push_front(testClass1);
		Assert::IsTrue(testList->isEmpty() == 0 && testList->get_size() == 1 && testList->at(0) == testClass1);
	}

	TEST_METHOD(pop_back)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		testList->pop_back();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == testClass1 && testList->at(1) == testClass2);
	}

	TEST_METHOD(pop_front)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		testList->pop_front();
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == testClass2 && testList->at(1) == testClass3);
	}

	TEST_METHOD(insert)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass3);

		testList->insert(1, testClass2);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 3 && testList->at(0) == testClass1 && testList->at(1) == testClass2 && testList->at(2) == testClass3);
	}

	TEST_METHOD(at)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		Assert::IsTrue(testList->at(0) == testClass1 && testList->at(1) == testClass2 && testList->at(2) == testClass3);
	}

	TEST_METHOD(remove)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		testList->remove(1);
		Assert::IsTrue(!testList->isEmpty() && testList->get_size() == 2 && testList->at(0) == testClass1 && testList->at(1) == testClass3);
	}

	TEST_METHOD(get_size)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		Assert::IsTrue(testList->get_size() == 3);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);
		testList->push_back(testClass3);

		testList->clear();
		Assert::IsTrue(testList->isEmpty());
	}

	TEST_METHOD(set)
	{
		testList->push_back(testClass1);
		testList->push_back(testClass2);

		testList->set(1, testClass3);
		Assert::IsTrue(testList->at(0) == testClass1 && testList->at(1) == testClass3);
	}
};

TEST_CLASS(Exceptions)
{
public:
	ListClass<int> * testList;

	TEST_METHOD_INITIALIZE(SetUp)
	{
		testList = new ListClass<int>();
	}

	TEST_METHOD_CLEANUP(CleanUp)
	{
		delete testList;
	}

	TEST_METHOD(pop_in_empty_list)
	{
		try
		{
			testList->pop_back();
		}
		catch (logic_error message)
		{
			Assert::AreEqual("The list is empty", message.what());
		}

		try
		{
			testList->pop_front();
		}
		catch (logic_error message)
		{
			Assert::AreEqual("The list is empty", message.what());
		}
	}

	TEST_METHOD(insert_with_invalid_argument)
	{
		try
		{
			testList->insert(-1,1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}

		try
		{
			testList->insert(2, 1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}
	}

	TEST_METHOD(remove_with_invalid_argument)
	{
		testList->push_back(10);
		try
		{
			testList->remove(-1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}

		try
		{
			testList->remove(1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}
	}

	TEST_METHOD(at_with_invalid_argument)
	{
		testList->push_back(10);
		try
		{
			testList->at(-1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}

		try
		{
			testList->at(1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}
	}

	TEST_METHOD(set_with_invalid_argument)
	{
		testList->push_back(10);
		try
		{
			testList->set(-1, 12);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}

		try
		{
			testList->set(1, 12);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index is greater than list size or less than zero", message.what());
		}
	}
};

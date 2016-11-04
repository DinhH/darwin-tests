
// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Darwin.h"

#include <iostream>
#include <ostream>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

// ----
// tests
// ----

// ----
// Species Class Tests
// ----

TEST(DarwinFixture, Species_Constructor1) {
  Species a("a");
  ASSERT_EQ(a.name, std::string("a"));}

TEST(DarwinFixture, Species_Constructor2) {
  Species a("c");
  ASSERT_EQ(a.name, std::string("c"));}

TEST(DarwinFixture, Species_Constructor3) {
  Species a("b");
  ASSERT_EQ(a.name, std::string("b"));}

TEST(DarwinFixture, Species_add_Instruction1) {
   Species a("a");
   a.add_Instruction(std::string("hop"));
   ASSERT_EQ(a.getInstruction(0).first, std::string("hop"));}

TEST(DarwinFixture, Species_add_Instruction2) {
   Species a("a");
   a.add_Instruction(std::string("hop"));
   a.add_Instruction(std::string("right"));
   ASSERT_EQ(a.getInstruction(1).first, std::string("right"));}


TEST(DarwinFixture, Species_add_Instruction3) {
   Species a("a");
   a.add_Instruction(std::string("hop"));
   a.add_Instruction(std::string("left"));
   ASSERT_EQ(a.getInstruction(0).first, std::string("hop"));}

TEST(DarwinFixture, Species_total1) {
  Species a("a");
   a.add_Instruction(std::string("hop"));
   a.add_Instruction(std::string("left"));
   a.add_Instruction(std::string("hop"));
   ASSERT_EQ(a.total(), 3);}


TEST(DarwinFixture, Species_total2) {
  Species a("a");
    a.add_Instruction(std::string("hop"));
    a.add_Instruction(std::string("hop"));
    ASSERT_EQ(a.total(), 2);}

TEST(DarwinFixture, Species_total3) {
   Species a("a");
   ASSERT_EQ(a.total(), 0);}

// TEST(DarwinFixture, Species_get_Instruction1) {
//    string str = std::string("hop");
//     Species example(str);
//     example.add_Instruction(str, 3);
//     std::pair<std::string, int> instr = example.getInstruction(3);
//     ASSERT_EQ(instr.first, std::string("hop"));}
//
// TEST(DarwinFixture, Species_get_Instruction2) {
//    string str = std::string("hop");
//     Species example(str);
//     example.add_Instruction(str, 3);
//     example.add_Instruction(str, 5);
//     std::pair<std::string, int> instr = example.getInstruction(0);
//     ASSERT_EQ(instr.first, std::string("hop"));}
//
// TEST(DarwinFixture, Species_get_Instruction3) {
//    string str = std::string("hop");
//     Species example(str);
//     example.add_Instruction(str, 0);
//     std::pair<std::string, int> instr = example.getInstruction(3);
//     ASSERT_EQ(instr.second, 0);}

// // ----
// // Creature Class Tests
// // ----

TEST(DarwinFixture, Creature_Constructor1) {
  Species a("a");
  Creature b(a);
  ASSERT_EQ(b.spc, &a);}

TEST(DarwinFixture, Creature_Constructor2) {
  Creature b(Species("a"));
  ASSERT_EQ(true, b.is_turn);}

TEST(DarwinFixture, Creature_Constructor3) {
  Creature b(Species("f"));
  ASSERT_EQ(true, b.is_turn);}

TEST(DarwinFixture, Creature_move1) {
  Species a("a");
  a.add_Instruction(std::string("hop"));
  a.add_Instruction(std::string("right"));
  Creature b(a);
  ASSERT_EQ(std::string("hop"), b.move().first);}

TEST(DarwinFixture, Creature_move2) {
  Species a("a");
  a.add_Instruction(std::string("hop"));
  a.add_Instruction(std::string("left"));
  Creature b(a);
  ASSERT_EQ(std::string("hop"), b.move().first);}

TEST(DarwinFixture, Creature_move3) {
  Species a("a");
  a.add_Instruction(std::string("left"));
  a.add_Instruction(std::string("right"));
  Creature b(a);
  ASSERT_EQ(std::string("left"), b.move().first);}

TEST(DarwinFixture, Creature_update_pc1) {
  Species a("a");
  a.add_Instruction(std::string("hop"));
  a.add_Instruction(std::string("left"));
  Creature b(a);
  b.update_pc();
  ASSERT_EQ(b.pc, 1);}

TEST(DarwinFixture, Creature_update_pc2) {
  Species a("a");
  a.add_Instruction(std::string("hop"));
  a.add_Instruction(std::string("right"));
  Creature b(a);
  b.update_pc();
  ASSERT_EQ(b.pc, 1);}

TEST(DarwinFixture, Creature_update_pc3) {
  Species a("a");
  a.add_Instruction(std::string("hop"));
  a.add_Instruction(std::string("infect"));
  Creature b(a);
  b.update_pc();
  ASSERT_EQ(b.pc, 1);}

TEST(DarwinFixture, Creature_transform1) {
  Species a("a");
  Species b("b");
  Creature c(b);
  c.transform(&a);
  ASSERT_EQ(c.spc, &a);}

TEST(DarwinFixture, Creature_transform2) {
  Species a("c");
  Creature b(a);
  ASSERT_THROW(b.transform(&a), std::invalid_argument);}

TEST(DarwinFixture, Creature_transform3) {
  Species a("a");
  Creature c(a);
  ASSERT_THROW(c.transform(&a), std::invalid_argument);}

// // ----
// // Darwin Class Tests
// // ----

TEST(DarwinFixture, Darwin_add_Creature1) {
  Darwin d(10, 10);
  ASSERT_EQ(d.height, 10);
  ASSERT_EQ(d.width, 10);}

TEST(DarwinFixture, Darwin_add_Creature2) {
  Darwin d(1, 1);
  ASSERT_EQ(d.height, 1);
  ASSERT_EQ(d.width, 1);}

TEST(DarwinFixture, Darwin_add_Creature3) {
    ASSERT_THROW(Darwin d(-1, -1), std::invalid_argument);}

// TEST(DarwinFixture, Darwin_run_Instruction1) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_run_Instruction2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_run_Instruction3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_p_turn1) {
  Darwin d(2, 2);
  Species a("a");
  a.add_Instruction("hop");
  Creature b(a, east);
  d.add_Creature(b, 0, 0);
  d.p_turn();
  ASSERT_EQ(&b, d.creature_on_board(std::pair<int, int>(0, 1)));}

TEST(DarwinFixture, Darwin_p_turn2) {
    Darwin d(1, 1);
    ASSERT_NO_THROW(d.p_turn(-2));}

// TEST(DarwinFixture, Darwin_p_turn3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_on_Grid1) {
  Darwin d(10, 10);
  ASSERT_TRUE(d.on_Grid(std::pair<int, int>(0, 0)));}

TEST(DarwinFixture, Darwin_on_Grid2) {
  Darwin d(10, 10);
  ASSERT_TRUE(d.on_Grid(std::pair<int, int>(-1, 0)));}

TEST(DarwinFixture, Darwin_on_Grid3) {
  Darwin d(10, 10);
  ASSERT_TRUE(d.on_Grid(std::pair<int, int>(0, -1)));}

// TEST(DarwinFixture, Darwin_creature_on_board1) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_creature_on_board2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_creature_on_board3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}


TEST(DarwinFixture, Darwin_is_near1) {
  Species s("s");
  Creature c(s, north);
  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);

  std::pair<int, int> x = std::make_pair(-1, 0);
  ASSERT_EQ(d.is_near(0, 0), x);}

// TEST(DarwinFixture, Darwin_is_near2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_is_near3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_hop1) {
  Species s("s");
  s.add_Instruction("hop");
  Creature c(s, east);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);
  Creature* before = d.creature_on_board(std::pair<int, int>(0, 0));

  d.hop(0,0);

  Creature* after = d.creature_on_board(std::pair<int, int>(0, 1));
  ASSERT_EQ(before, after); }

TEST(DarwinFixture, Darwin_hop2) {
  Species s("s");
    s.add_Instruction("hop");
    Creature c(s, east);

    Darwin d(2, 2);
    d.add_Creature(c, 0, 1);
    Creature* before = d.creature_on_board(std::pair<int, int>(0, 1));

    d.hop(0, 1);

    Creature* after = d.creature_on_board(std::pair<int, int>(0, 1));
    ASSERT_EQ(before, after);}

TEST(DarwinFixture, Darwin_left1) {
    Species s("s");
    s.add_Instruction("left");
    Creature c(s, west);

    Darwin d(2, 2);
    d.add_Creature(c, 0, 0);
    d.left(0, 0);

    ASSERT_EQ(c.dir, south);}

// TEST(DarwinFixture, Darwin_left2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_left3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_right1) {
  Species s("s");
  s.add_Instruction("right");
  Creature c(s, west);

  Darwin d(2,2);
  d.add_Creature(c, 0, 0);
  d.right(0, 0);

  ASSERT_EQ(c.dir, north);}

// TEST(DarwinFixture, Darwin_right2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_right3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_infect1) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_infect2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_infect3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_if_empty1) {
  Species s("s");
  s.add_Instruction("if_empty", 2);
  s.add_Instruction("right");
  s.add_Instruction("left");
  Creature c(s, east);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);

  d.if_empty(0, 0, 2);
  ASSERT_EQ(c.pc, 2);
  ASSERT_EQ(c.move().first, "left");}

// TEST(DarwinFixture, Darwin_if_empty2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_if_empty3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_if_wall1) {
  Species s("s");
  s.add_Instruction("if_wall", 2);
  s.add_Instruction("right");
  s.add_Instruction("left");
  Creature c(s, west);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);

  d.if_wall(0, 0, 2);
  ASSERT_EQ(c.pc, 2);
  ASSERT_EQ(c.move().first, "left");}

// TEST(DarwinFixture, Darwin_if_wall2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_if_wall3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_if_enemy1) {
  Species s1("s1");
  Species s2("s2");
  s1.add_Instruction("if_enemy", 2);
  s1.add_Instruction("right");
  s1.add_Instruction("left");
  Creature c1(s1, east);
  Creature c2(s2, east);

  Darwin d(2, 2);
  d.add_Creature(c1, 0, 0);
  d.add_Creature(c2, 0, 1);

  d.if_enemy(0, 0, 2);

  ASSERT_EQ(c1.pc, 2);
  ASSERT_EQ(c1.move().first, "left");}

// TEST(DarwinFixture, Darwin_if_enemy2) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

// TEST(DarwinFixture, Darwin_if_enemy3) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}

TEST(DarwinFixture, Darwin_if_random1) {
  std::srand(0);
  Species s("s");
  s.add_Instruction("if_enemy", 2);
  s.add_Instruction("right");
  s.add_Instruction("right");
  Creature c(s, west);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);
  d.if_random(0, 0, 2);

  ASSERT_NE(c.pc, 0);}

TEST(DarwinFixture, Darwin_if_random2) {
  std::srand(0);
  Species s("s");
  s.add_Instruction("if_enemy", 2);
  s.add_Instruction("hop");
  s.add_Instruction("left");
  Creature c(s, north);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);
  d.if_random(0, 0, 2);

  ASSERT_NE(c.pc, 0);}

TEST(DarwinFixture, Darwin_if_random3) {
  std::srand(0);
  Species s("s");
  s.add_Instruction("if_enemy", 2);
  s.add_Instruction("right");
  s.add_Instruction("left");
  Creature c(s, east);

  Darwin d(2, 2);
  d.add_Creature(c, 0, 0);
  d.if_random(0, 0, 2);

  ASSERT_NE(c.pc, 0);}

TEST(DarwinFixture, Darwin_go1) {
  Species s("s");
  s.add_Instruction(std::string("hop"));
  s.add_Instruction(std::string("if_wall", 0));
  Creature c(s);

  Darwin d(2,2);
  d.add_Creature(c, 0, 0);
  d.go(0, 0, 0);

  ASSERT_EQ(c.pc, 0);
  ASSERT_EQ(c.move().first, "hop");}

TEST(DarwinFixture, Darwin_go2) {
  Species s("s");
  s.add_Instruction(std::string("hop"));
  s.add_Instruction(std::string("go", 0));
  Creature c(s);

  Darwin d(2,2);
  d.add_Creature(c, 0, 0);
  d.go(0, 0, 0);

  ASSERT_EQ(c.pc, 0);
  ASSERT_EQ(c.move().first, "hop");}

TEST(DarwinFixture, Darwin_go3) {
  Species s("s");
  s.add_Instruction(std::string("hop"));
  s.add_Instruction(std::string("if_enemy", 0));
  Creature c(s);

  Darwin d(2,2);
  d.add_Creature(c, 0, 0);
  d.go(0, 0, 0);

  ASSERT_EQ(c.pc, 0);
  ASSERT_EQ(c.move().first, "hop");}

TEST(DarwinFixture, Darwin_print1) {
  Species s("s");
  Creature c(s);
  Darwin d(1, 2);

  std::ostringstream o;
  d.print(o);

  ASSERT_EQ("Turn = 0.\n  01\n0 ..\n\n", o.str());}

TEST(DarwinFixture, Darwin_print2) {
  Species s("s");
  Creature c(s);
  Darwin d(1, 1);

  std::ostringstream o;
  d.print(o);

  ASSERT_EQ("Turn = 0.\n  0\n0 .\n\n", o.str()); }

TEST(DarwinFixture, Darwin_print3) {
    Species s("s");
    Creature c(s);
    Darwin d(2, 1);

    std::ostringstream o;
    d.print(o);

    ASSERT_EQ("Turn = 0.\n  0\n0 .\n1 .\n\n", o.str());}

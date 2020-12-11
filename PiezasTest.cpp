/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(PiezasTest, InvalidPlace)
{
	Piezas B;
	ASSERT_EQ(B.dropPiece(-1), Invalid);
}
TEST(PiezasTest, InvalidPlace2)
{
	Piezas B;
	ASSERT_EQ(B.dropPiece(5), Invalid);
}
TEST(PiezasTest, InvalidPlacefull)
{
	Piezas B;
	B.dropPiece(0);
	B.dropPiece(1);
	B.dropPiece(0);
	B.dropPiece(1);
	B.dropPiece(0);
	B.dropPiece(1);
	B.dropPiece(0);

	ASSERT_EQ(B.dropPiece(0), Invalid);
}
TEST(PiezasTest, validPlace)
{
	Piezas Board;
	ASSERT_EQ(Board.pieceAt(0,0), Blank);
}

TEST(PiezasTest, pieceAtBoardO)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(1);
	Board.dropPiece(3);

	ASSERT_EQ(Board.pieceAt(0,1), O);
}

TEST(PiezasTest, pieceAtBoardX)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(1);
	Board.dropPiece(3);

	ASSERT_EQ(Board.pieceAt(0,0), X);
}

TEST(PiezasTest, GamestatetestO)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(1);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(1);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);

	ASSERT_EQ(Board.gameState(), O);
}

TEST(PiezasTest, gamestate_is_blank)
{
	Piezas Board;
	ASSERT_EQ(Board.gameState(), Blank);
}
//this wil fail
TEST(PiezasTest, GamestatetestX)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(0);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);

	//Board.reset();

	ASSERT_EQ(Board.gameState(), X);
}

TEST(PiezasTest, resetBoard)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.reset();
	ASSERT_EQ(Board.pieceAt(0,0), Blank );
}

TEST(PiezasTest, invalidpieceAt)
{
	Piezas Board;
	ASSERT_EQ(Board.pieceAt(0,-1), Invalid);
}

TEST(PiezasTest, invalidpieceAtover)
{
	Piezas Board;
	ASSERT_EQ(Board.pieceAt(0,7), Invalid);
}

TEST(PiezasTest, pieceAtNoPiece)
{
	Piezas Board;
	ASSERT_EQ(Board.pieceAt(2,3), Blank);
}

TEST(PiezasTest, gamestatewin)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(0);
	Board.dropPiece(2);
	Board.dropPiece(0);
	Board.dropPiece(3);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);
	
	ASSERT_EQ(Board.gameState(), O);
}
TEST(PiezasTest, gameSatetie)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(1);
	ASSERT_EQ(Board.gameState(), Blank);
}

TEST(PiezasTest, dropPieceOutbounds)
{
	Piezas Board;
	ASSERT_EQ(Board.dropPiece(6), Invalid);
}

TEST(PiezasTest, dropPieceOutbound2)
{
	Piezas Board;
	ASSERT_EQ(Board.dropPiece(-1), Invalid);
}
TEST(PiezasTest, gamelose)
{
	Piezas Board;
	ASSERT_EQ(Board.dropPiece(-1), Invalid);
}
TEST(PiezasTest, gamestateOwin)
{
	Piezas Board;
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(0);
	Board.dropPiece(1);
	Board.dropPiece(0);

	ASSERT_EQ(Board.gameState(), O);

}

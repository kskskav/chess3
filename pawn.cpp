#include "pawn.h"

Pawn::Pawn(int x, int y, bool color) : ChessPiece(x, y, color)
{
    if (color) {
        this->setPixmap(QPixmap::fromImage(*whiteImage).scaled(90,90));
    }
    else {
        this->setPixmap(QPixmap::fromImage(*blackImage).scaled(90,90));
    }

    weight = 1;
    name = "Pawn";
}

bool Pawn::figureCanMove(const Cell *start, const Cell *end)
{
    if ((start->column == end->column))
    {
        if (!this->color &&  (end->row - start->row == 1 || (end->row - start->row == 2 && !hasMoved))) {
            hasMoved = true;
            return true;
        }
        else if (this->color && ((start->row - end->row == 2 && !hasMoved) || start->row - end->row == 1)) {
             hasMoved = true;
            return true;
        }
    }
      else if ((abs(start->column - end->column) == abs(end->row - start->row) == 1))
        {
            if (!this->color && end->row - start->row == 1 && forpawn == true)
            {
                return true;
            }

            else if (this->color && start->row - end->row == 1 && forpawn == true)
            {
                return true;
            }
        }

    //// нужно ещё, чтобы было !hasMoved у соперника
     if ((abs (start->column - end->column) == abs (start->row - end->row) == 1) && taking_on_the_aisle == true)
       {
           if (!this->color && end->row - start->row == 1)
           {
               return true;
           }

           else if (this->color && start->row - end->row == 1)
           {
               return true;
           }
       }
    return false;
}

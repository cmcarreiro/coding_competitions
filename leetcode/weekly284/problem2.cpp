//got wrong answer

class Solution {
public:

    class Artifact {
        public:
            int x_1;
            int y_1;
            int x_2;
            int y_2;
            int num_cells;
            bool cell_one_uncovered = false;
            bool cell_two_uncovered = false;
            bool cell_three_uncovered = false ;
            bool cell_four_uncovered = false;
        
        
            Artifact(vector<int> positions) {
                x_1 = positions.at(0);
                y_1 = positions.at(1);
                x_2 = positions.at(2);
                y_2 = positions.at(3);

                //it either only has 1 cell, 2 cells, or 4 cells
                
                //checking if it's only one cell
                if (x_1 == x_2 && y_1 == y_2) {
                    num_cells = 1;
                }
                
                //check if it's vertical
                else if ( x_1 == x_2 ) {
                    num_cells = 2;
                }
                
                //check if it's horizontal
                else if ( y_1 == y_2) {
                    num_cells = 2;
                }
                
                //it occupies four cells
                else {
                    num_cells = 4;
                }
            }

            bool isOneCell() {
                return (this->num_cells == 1);
            }

            bool isHorizontal() {
                return (this->num_cells == 2 && this->y_1 == this->y_2);
            }

            bool isVertical() {
                return (this->num_cells == 2 && this->x_1 == this->x_2);
            }

            bool isFourCells() {
                return (this->num_cells == 4);
            }

            void dig(vector<int> digSite) {
                int dig_x = digSite.at(0);
                int dig_y = digSite.at(1);

                if (dig_x == this->x_1 && dig_y == this->y_1) {
                    
                    this->cell_one_uncovered = true;
                }

                else if (dig_x == this->x_2 && dig_y == this->y_1) {
                    
                    this->cell_two_uncovered = true;
                }

                else if (dig_x == this->x_1 && dig_y == this->y_2) {
                    
                    this->cell_three_uncovered = true;
                }
                
                else if (dig_x == this->x_2 && dig_y == this->y_2) {
                    
                    this->cell_four_uncovered = true;
                }

                return;
            }

            bool isArtifactUncovered() {
                if (this->isOneCell()) {
                    return this->cell_one_uncovered;
                }

                else if (this->isHorizontal()) {
                    return (this->cell_one_uncovered && this->cell_two_uncovered);
                }

                else if (this->isVertical()) {
                    return (this->cell_one_uncovered && this->cell_three_uncovered);
                }

                else if (this->isFourCells()) {
                    return (this->cell_one_uncovered && this->cell_two_uncovered && this->cell_three_uncovered && this->cell_four_uncovered);
                }
                
                return false;

            }
    };
    
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        int uncovered_artifacts = 0;
        
        for (vector<int> artifact : artifacts) {

            
            Artifact* artf = new Artifact(artifact);

            for ( vector<int> dig_site : dig) {
                
                artf->dig(dig_site);
                if (artf->isArtifactUncovered()) {
                    uncovered_artifacts++;
                    break;
                    
                }
            }
        }

        return uncovered_artifacts;
    }
};
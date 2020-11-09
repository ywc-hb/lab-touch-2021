/* 
 * Author : Grégoire Lefaure
 */

#include "Pattern.hpp"

void Pattern::display(std::array<std::array<int, 4>, 13> & pattern) {
	for(int i {0}; i < 13; i++) {
		LCD::Draw_Line(pattern[i][0], pattern[i][1], pattern[i][2], pattern[i][3], BLACK, DOT_PIXEL_1);
	}
}

std::array<std::array<int, 4>, 13>& Pattern::choose_pattern(int x, int y) {
	if(x <= 80  && y <= 64) {
		return patternNW;
	}
	else if(x > 80 && y <= 64) {
		return patternNE;
	}
	else if(x <= 80 && y > 64) {
		return patternSW;
	}
	else {
		return patternSE;
	}

}

WallOrientation Pattern::has_touched(int x, int y, int rad) {
	std::array<std::array<int, 4>, 13> & pattern_to_test = choose_pattern(x, y);

	// Début des tests
	for(auto & i : pattern_to_test) {
		std::vector<int> closest;
		// Définition du point du mur i le plus proche de la balle
		if(i[0] == i[2]) { // Teste si le mur horizontal ou non
			if(y >= i[1] && y <= i[3]) {
				closest.push_back(i[0]);
				closest.push_back(y);
			}
			else if(y < i[1]) {
				closest.push_back(i[0]);
				closest.push_back(i[1]);
			}
			else if(y > i[3]) {
				closest.push_back(i[0]);
				closest.push_back(i[3]);
			}
		}
		else {
			if(x >= i[0] && x <= i[2]) {
				closest.push_back(x);
				closest.push_back(i[1]);
			}
			else if(x < i[0]) {
				closest.push_back(i[0]);
				closest.push_back(i[1]);
			}
			else if(x > i[2]) {
				closest.push_back(i[2]);
				closest.push_back(i[1]);
			}
		}
		double distance { std::sqrt(std::pow(closest[0] - x, 2) + std::pow(closest[1] - y, 2)) }; // Distance entre le centre de l'objet et le point le plus proche

		if(distance <= rad) {
			if(i[0] == i[2]) {
				return WallOrientation::Horizontal;
			}
			else {
				return WallOrientation::Vertical;
			}
		}
		else {
			return WallOrientation::None;
		}
	}
}

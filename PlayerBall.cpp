/* 
 * Author : Grégoire Lefaure
 */

#include "PlayerBall.hpp"
#include "Pattern.hpp"

PlayerBall::PlayerBall(int rad, int color, int x, int y, int speed) 
	: m_rad(rad), m_color(color), m_x(x), m_y(y), m_speed(speed) {}


Direction PlayerBall::move(Direction direction) {
	int new_x { m_x };
	int new_y {m_y };
	switch(direction) {
	case Direction::North: new_y -= m_speed;
								 break;
	
	case Direction::South: new_y += m_speed;
								 break;
	
	case Direction::East: new_x += m_speed;
								break;
	
	case Direction::West: new_x -= m_speed;
								break;
	
	case Direction::North_East: new_x += m_speed;
										new_y -= m_speed;
										break;
	
	case Direction::North_West: new_x -= m_speed;
										new_y -= m_speed;
										break;

	case Direction::South_East: new_x += m_speed;
										new_y += m_speed;
										break;

	case Direction::South_West: new_x -= m_speed;
										new_y += m_speed;
										break;
	}

	auto where = Pattern::has_touched(new_x, new_y, m_rad);
	if(where == WallOrientation::None) {
		PlayerBall::display(new_x, new_y);
		m_x = new_x;
		m_y = new_y;
		return direction;
	}
	else {
		switch(direction) {
		case Direction::North: return Direction::South;
									 break;
		
		case Direction::South: return Direction::North;
									 break;
		
		case Direction::East: return Direction::West;
									break;
		
		case Direction::West: return Direction::East;
									break;
		
		case Direction::North_East: if(where == WallOrientation::Vertical) {
												return Direction::North_West;
											}
											else {
												return Direction::South_East;
											}
											break;
		
		case Direction::North_West: if(where == WallOrientation::Vertical) {
												return Direction::North_East;
											}
											else {
												return Direction::South_West;
											}
											break;

		case Direction::South_East: if(where == WallOrientation::Vertical) {
												return Direction::South_West;
											}
											else {
												return Direction::North_East;
											}
											break;

		case Direction::South_West: if(where == WallOrientation::Vertical) {
												return Direction::South_East;
											}
											else {
												return Direction::North_West;
											}
											break;
		}
	}
}

void PlayerBall::display(int new_x, int new_y) {
	LCD::Draw_Circle(m_x, m_y, m_rad, WHITE);
	LCD::Display_Window(m_x - m_rad, m_y - m_rad, m_x + m_rad, m_y +m_rad);
	LCD::Draw_Circle(new_x, new_y, m_rad, GREEN);
	LCD::Display_Window(new_x - m_rad, new_y - m_rad, new_x + m_rad, new_y +m_rad);
}

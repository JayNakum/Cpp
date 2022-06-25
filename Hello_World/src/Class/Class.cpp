struct vec2
{
    float x, y;
};


struct PlayerS
{
    int speed;
    void move(int xa, int ya) {
        x += xa + speed;
        y += ya + speed;
    }
private:
    int x, y;
};


class Player
{
    int x, y;

public:
    int speed;
    void move(int xa, int ya) {
        x += xa + speed;
        y += ya + speed;
    }
};



void test() {
    Player player1;
    player1.speed = 50;
    player1.move(1, -1);
}
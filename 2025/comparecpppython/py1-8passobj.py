class Square:
    def __init__(self, s=1):
        print("Const ...")
        self.side = s
    def __del__(self):
        print("Destr ...")
    def set_side(self, v):
        self.side = v
    def get_side(self):
        return self.side
def print_square(s):
    print(s.get_side())
    s.set_side(20)
if __name__ == "__main__":
    sq = Square(10)
    print_square(sq)
    print(sq.get_side())
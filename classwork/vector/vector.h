struct vector
{

        int size, capacity;
        int *data;

        vector();

        vector (int capacity_);

        ~vector();

        int get_size();
        void print();
        void resize();
        void push_back(int n);
};

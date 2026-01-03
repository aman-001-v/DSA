class Solution {
public:
    int numOfWays(int n) {
        const long MOD = 1000000007;
        long typeA = 6; // ABA patterns
        long typeB = 6; // ABC patterns

        for (int i = 2; i <= n; ++i) {
            long nextA = (3 * typeA + 2 * typeB) % MOD;
            long nextB = (2 * typeA + 2 * typeB) % MOD;
            typeA = nextA;
            typeB = nextB;
        }

        return (typeA + typeB) % MOD;
    }
};


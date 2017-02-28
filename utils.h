#ifndef CONNECT4_UTILS_H
#define CONNECT4_UTILS_H

int ask_index(const char* allowed_ans);

inline char ask(const char* allowed_ans) {
    return allowed_ans[ask_index(allowed_ans)];
}

#endif // CONNECT4_UTILS_H

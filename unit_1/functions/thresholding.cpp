#include "pixelfuncs.hpp"

unsigned char ridler_calvard(cv::Mat &img) {
    uint32_t pdf[256] = {};
    // calculate pdf
    cv::MatConstIterator_<uchar> iter_end = img.end<uchar>();
    cv::MatIterator_<uchar> iter = img.begin<uchar>();
    for(; iter != iter_end; iter++) {
        pdf[*iter]++;
    }

    // prep m_0 & m_1
    uint32_t m_0[256] = {};
    uint32_t m_1[256] = {};
    m_0[0] = m_0[0];
    m_1[0] = 0;
    for(size_t i = 1; i < 256; i++) {
        m_0[i] = m_0[i-1] + pdf[i];
        m_1[i] = m_1[i-1] + pdf[i]*i;
    }

    float t = 127, t_old = 0;
    float u_bg, u_fg;
    while (true) {
        t_old = t;
        u_bg = m_1[(size_t) t] / (float) m_0[(size_t)t];
        u_fg = (m_1[255] - m_1[(size_t)t]) / (float)(m_0[255] - m_0[(size_t)t]);
        t = (u_fg + u_bg) / 2.0;
        if (t - t_old < 0.1 && t - t_old > -0.1) {
            return t;
        }
    }
    return t;
}
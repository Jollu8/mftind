#pragma once

#include "imatcher.h"
#include "istatcollector.h"
#include "using.h"

class Matcher : public IMatcher {
public:
    Matcher(IStatCollector *statCollector, Mask mask);

    void match(BufferInfo &&bufferInfo) override;

private:
    IStatCollector *m_statCollector;
    Mask m_mask;
};
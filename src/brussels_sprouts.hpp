#pragma once

#include <string>

#include "plot.hpp"

class BrusselsSprouts : public Plot {
  private:
    int days = 0;
    bool watered = false;
    static const int days_to_sprout = 5;
    static const int days_to_maturity = 10;

  public:
    std::string symbol() override;
    void end_day() override;
    void water() override;
    bool is_harvestable() override;
    int get_days();
};


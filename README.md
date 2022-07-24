# CAPACITANCE-METER

Range of capacitance meter : 0.1uF - 4F
Principle of working : Charging and Discharging of capacitor
                     A capacitor takes one time constant to charge to approximately 63.2 % of its full charge.So, by measuring the time taken to charge and having the                        resistance value used to charge the capacitor , we can get the value of capacitance by dividing them.
Resistor used to charge the capacitor : 10K ohm

CALCULATIONS:
Arduino ADC has 10 bits , so 0 would be 0 and 5 would be 1024 , so 63.2% would be 648.Hence , we will stop the timer at 648 and measure the time.


/*

  Development environment specifics:
  Arduino IDE 1.8.1

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.


  ---AVAILABLE FUNCTIONS---
  AS726X(TwoWire &wirePort = Wire, byte gain = 3, byte measurementMode = 3);
  void takeMeasurements();
  void takeMeasurementsWithBulb();
  void printMeasurements();
  byte getTemperature();
  float getTemperatureF();
  void setMeasurementMode(byte mode);
  boolean dataAvailable();
  void enableIndicator();
  void disableIndicator();
  void setIndicatorCurrent(byte current);
  void enableBulb();
  void disableBulb();
  void setBulbCurrent(byte current);
  void softReset();
  void setGain(byte gain);
  void setIntegrationTime(byte integrationValue);
  void enableInterrupt();
  void disableInterrupt();

  //Get the various color readings
  int getViolet();
  int getBlue();
  int getGreen();
  int getYellow();
  int getOrange();
  int getRed();

  //Get the various NIR readings
  int getR();
  int getS();
  int getT();
  int getU();
  int getV();
  int getW();

  //Returns the various calibration data
  float getCalibratedViolet();
  float getCalibratedBlue();
  float getCalibratedGreen();
  float getCalibratedYellow();
  float getCalibratedOrange();
  float getCalibratedRed();

  float getCalibratedR();
  float getCalibratedS();
  float getCalibratedT();
  float getCalibratedU();
  float getCalibratedV();
  float getCalibratedW();
*/

#include "AS726X.h"

AS726X sensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  
  sensor.begin();
}

void loop() {
  //enable the LED bulb
  sensor.enableBulb();
  
  //take measurements
  sensor.takeMeasurements();
  
  //disable the LED bulb
  sensor.disableBulb();
  
  //Prints all measurements
  if (sensor.getVersion() == SENSORTYPE_AS7262)
  {
    //Visible readings
    Serial.print(" Reading: V[");
    Serial.print(sensor.getCalibratedViolet(), 2);
    Serial.print("] B[");
    Serial.print(sensor.getCalibratedBlue(), 2);
    Serial.print("] G[");
    Serial.print(sensor.getCalibratedGreen(), 2);
    Serial.print("] Y[");
    Serial.print(sensor.getCalibratedYellow(), 2);
    Serial.print("] O[");
    Serial.print(sensor.getCalibratedOrange(), 2);
    Serial.print("] R[");
    Serial.print(sensor.getCalibratedRed(), 2);
  }
  else if (sensor.getVersion() == SENSORTYPE_AS7263)
  {
    //Near IR readings
    Serial.print(" Reading: R[");
    Serial.print(sensor.getCalibratedR(), 2);
    Serial.print("] S[");
    Serial.print(sensor.getCalibratedS(), 2);
    Serial.print("] T[");
    Serial.print(sensor.getCalibratedT(), 2);
    Serial.print("] U[");
    Serial.print(sensor.getCalibratedU(), 2);
    Serial.print("] V[");
    Serial.print(sensor.getCalibratedV(), 2);
    Serial.print("] W[");
    Serial.print(sensor.getCalibratedW(), 2);
  }

  Serial.print("] tempF[");
  Serial.print(sensor.getTemperatureF(), 1);
  Serial.print("]");

  Serial.println();
}

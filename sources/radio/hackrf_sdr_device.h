#pragma once

#include <config.h>
#include <libhackrf/hackrf.h>
#include <radio/sdr_device.h>

class HackrfSdrDevice : public SdrDevice {
 public:
  HackrfSdrDevice(const Config& config, const std::string& serial);
  ~HackrfSdrDevice() override;

  static std::vector<std::string> listDevices();
  void startStream(const FrequencyRange& frequencyRange, Callback&& callback) override;
  std::vector<uint8_t> readData(const FrequencyRange& frequencyRange) override;

 private:
  const Config& m_config;
  const std::string m_serial;
};
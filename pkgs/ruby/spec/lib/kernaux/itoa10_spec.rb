# frozen_string_literal: true

require 'spec_helper'

RSpec.describe KernAux, '.itoa10' do
  if described_class.singleton_class.method_defined? :itoa10
    subject(:itoa10) { described_class.itoa10 number }

    let(:number) { rand((-2**63)..(2**63 - 1)) }

    it { is_expected.to be_instance_of String }
    it { is_expected.to be_frozen }
    it { is_expected.to eq number.to_s }

    context 'when number is 0' do
      let(:number) { 0 }

      it { is_expected.to eq '0' }
    end

    context 'when number is 1' do
      let(:number) { 1 }

      it { is_expected.to eq '1' }
    end

    context 'when number is -1' do
      let(:number) { -1 }

      it { is_expected.to eq '-1' }
    end

    context 'when number is min int64_t' do
      let(:number) { -2**63 }

      it { is_expected.to eq number.to_s }
    end

    context 'when number is max int64_t' do
      let(:number) { 2**63 - 1 }

      it { is_expected.to eq number.to_s }
    end

    context 'when number is lesser than min uint64_t' do
      let(:number) { -2**63 - 1 }

      specify do
        expect { itoa10 }.to raise_error \
          RangeError, 'bignum too big to convert into `long long\''
      end
    end

    context 'when number is greater than max uint64_t' do
      let(:number) { 2**63 }

      specify do
        expect { itoa10 }.to raise_error \
          RangeError, 'bignum too big to convert into `long long\''
      end
    end
  end
end

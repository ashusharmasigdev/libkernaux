# frozen_string_literal: true

# Copyright (c) 2014-2019 Marco Paland <info@paland.com>
# Author: Marco Paland (info@paland.com) PALANDesign Hannover, Germany

require 'spec_helper'

RSpec.describe KernAux, '.sprintf' do
  subject(:sprintf) { described_class.sprintf 'Hello, ', ['%s', 'World'], '!' }

  it { is_expected.to be_instance_of String }
  it { is_expected.to be_frozen }
  it { is_expected.to eq 'Hello, World!' }

  context 'using original tests' do
    [
      [' 4232',                  ['% d', 4232]],
      ['This is a test of 12EF', ['This is a test of %X', 0x12EF]],
      ['-1000',                  ['%d', -1000]],
      ['-1',                     ['%d', -1]],
      ['2345',                   ['%d', 2345]],
      ['3 -1000 test',           ['%d ', 3], ['%d ', -1000], ['%s', 'test']],
      ['3 -1000 test',           ['%d', 3], [' %d', -1000], [' %s', 'test']],
      ['3 -1000 test',           ['%d', 3], ' ', ['%d', -1000], ' ', ['%s', 'test']],
      # space flag
      [' 42',                    ['% d', 42]],
      ['-42',                    ['% d', -42]],
      ['   42',                  ['% 5d', 42]],
      ['  -42',                  ['% 5d', -42]],
      ['             42',        ['% 15d', 42]],
      ['            -42',        ['% 15d', -42]],
      ['        -42.987',        ['% 15.3f', -42.987]],
      ['         42.987',        ['% 15.3f', 42.987]],
      ['Hello testing',          ['% s', 'Hello testing']],
      [' 1024',                  ['% d', 1024]],
      ['-1024',                  ['% d', -1024]],
      [' 1024',                  ['% i', 1024]],
      ['-1024',                  ['% i', -1024]],
      ['1024',                   ['% u', 1024]],
      ['4294966272',             ['% u', 4_294_966_272]],
      ['777',                    ['% o', 511]],
      ['37777777001',            ['% o', 4_294_966_785]],
      ['1234abcd',               ['% x', 305_441_741]],
      ['edcb5433',               ['% x', 3_989_525_555]],
      ['1234ABCD',               ['% X', 305_441_741]],
      ['EDCB5433',               ['% X', 3_989_525_555]],
      ['x',                      ['% c', 'x']],
      # + flag
      ['+42',                    ['%+d', 42]],
      ['-42',                    ['%+d', -42]],
      ['  +42',                  ['%+5d', 42]],
      ['  -42',                  ['%+5d', -42]],
      ['            +42',        ['%+15d', 42]],
      ['            -42',        ['%+15d', -42]],
      ['Hello testing',          ['%+s', 'Hello testing']],
      ['+1024',                  ['%+d', 1024]],
      ['-1024',                  ['%+d', -1024]],
      ['+1024',                  ['%+i', 1024]],
      ['-1024',                  ['%+i', -1024]],
      ['1024',                   ['%+u', 1024]],
      ['4294966272',             ['%+u', 4_294_966_272]],
      ['777',                    ['%+o', 511]],
      ['37777777001',            ['%+o', 4_294_966_785]],
      ['1234abcd',               ['%+x', 305_441_741]],
      ['edcb5433',               ['%+x', 3_989_525_555]],
      ['1234ABCD',               ['%+X', 305_441_741]],
      ['EDCB5433',               ['%+X', 3_989_525_555]],
      ['x',                      ['%+c', 'x']],
      ['+',                      ['%+.0d', 0]],
      # 0 flag
      ['42',                     ['%0d', 42]],
      ['42',                     ['%0ld', 42]],
      ['-42',                    ['%0d', -42]],
      ['00042',                  ['%05d', 42]],
      ['-0042',                  ['%05d', -42]],
      ['000000000000042',        ['%015d', 42]],
      ['-00000000000042',        ['%015d', -42]],
      ['000000000042.12',        ['%015.2f', 42.1234]],
      ['00000000042.988',        ['%015.3f', 42.9876]],
      ['-00000042.98760',        ['%015.5f', -42.9876]],
      # - flag
      ['42',                     ['%-d', 42]],
      ['-42',                    ['%-d', -42]],
      ['42   ',                  ['%-5d', 42]],
      ['-42  ',                  ['%-5d', -42]],
      ['42             ',        ['%-15d', 42]],
      ['-42            ',        ['%-15d', -42]],
      ['42',                     ['%-0d', 42]],
      ['-42',                    ['%-0d', -42]],
      ['42   ',                  ['%-05d', 42]],
      ['-42  ',                  ['%-05d', -42]],
      ['42             ',        ['%-015d', 42]],
      ['-42            ',        ['%-015d', -42]],
      ['42',                     ['%0-d', 42]],
      ['-42',                    ['%0-d', -42]],
      ['42   ',                  ['%0-5d', 42]],
      ['-42  ',                  ['%0-5d', -42]],
      ['42             ',        ['%0-15d', 42]],
      ['-42            ',        ['%0-15d', -42]],
      ['-4.200e+01     ',        ['%0-15.3e', -42.0]],
      ['-42.0          ',        ['%0-15.3g', -42.0]],
      # # flag
      ['',                       ['%#.0x', 0]],
      ['0',                      ['%#.1x', 0]],
      ['',                       ['%#.0llx', 0]],
      ['0x0000614e',             ['%#.8x', 0x614e]],
      ['0b110',                  ['%#b', 6]],
      # specifier
      ['Hello testing',          'Hello testing'],
      ['Hello testing',          ['Hello testing%s']],
      ['Hello testing',          ['Hello testing%s', '']],
      ['Hello testing',          ['%s', 'Hello testing']],
      ['1024',                   ['%d', 1024]],
      ['-1024',                  ['%d', -1024]],
      ['1024',                   ['%i', 1024]],
      ['-1024',                  ['%i', -1024]],
      ['1024',                   ['%u', 1024]],
      ['4294966272',             ['%u', 4_294_966_272]],
      ['777',                    ['%o', 511]],
      ['37777777001',            ['%o', 4_294_966_785]],
      ['1234abcd',               ['%x', 305_441_741]],
      ['edcb5433',               ['%x', 3_989_525_555]],
      ['1234ABCD',               ['%X', 305_441_741]],
      ['EDCB5433',               ['%X', 3_989_525_555]],
      ['%',                      ['%%']],
      # width
      ['Hello testing',          ['%1s', 'Hello testing']],
      ['1024',                   ['%1d', 1024]],
      ['-1024',                  ['%1d', -1024]],
      ['1024',                   ['%1i', 1024]],
      ['-1024',                  ['%1i', -1024]],
      ['1024',                   ['%1u', 1024]],
      ['4294966272',             ['%1u', 4_294_966_272]],
      ['777',                    ['%1o', 511]],
      ['37777777001',            ['%1o', 4_294_966_785]],
      ['1234abcd',               ['%1x', 305_441_741]],
      ['edcb5433',               ['%1x', 3_989_525_555]],
      ['1234ABCD',               ['%1X', 305_441_741]],
      ['EDCB5433',               ['%1X', 3_989_525_555]],
      ['x',                      ['%1c', 'x']],
    ].each do |expected, *args|
      it "transforms #{args.inspect} to #{expected.inspect}" do
        expect(described_class.sprintf(*args)).to eq expected
      end
    end
  end
end
